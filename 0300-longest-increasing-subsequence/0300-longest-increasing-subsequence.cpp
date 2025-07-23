class Solution {
public:
    // Binary Search + DP ~ O ( n log n )
    int lengthOfLISBS(vector<int>& nums) {
        vector<int> sub;

        for (int num : nums) {
            auto it = lower_bound(sub.begin(), sub.end(), num);

            // extend the sequence
            if (it == sub.end()) {
                sub.push_back(num);
            } else { // replace the sequence
                *it = num;
            }
        }
        return sub.size();
    }

    // Recursion ~ O ( 2 ^ n )
    int lengthOfLISDP(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return lis(0, -1, nums, dp);
    }

    // DP ~ O ( n ^ 2)
    /* Goal of the DP approach:

       We are computing:

          For each i, what is the length of the Longest Increasing Subsequence
       (LIS) that ends at index i?

          To do that, we consider every previous index j < i, because:

          We are asking: “Can nums[i] be added to an increasing subsequence that
       ends at j?”

          If yes (i.e., nums[j] < nums[i]), then we can extend that subsequence
       by 1.

    */

    // dp[i]=length of LIS ending at index i

    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(
            N, 1); // dp[i] starts with 1 (each element is an LIS of length 1)

        int maxLength = 1;
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLength = max(maxLength, dp[i]);
        }

        return maxLength;
    }

private:
    int lis(int index, int prevIndex, vector<int>& nums,
            vector<vector<int>>& dp) {
        if (index == nums.size())
            return 0;

        if (prevIndex != -1 && dp[index][prevIndex] != -1)
            return dp[index][prevIndex];

        int take = 0;
        if (prevIndex == -1 || nums[index] > nums[prevIndex]) {
            take = 1 + lis(index + 1, index, nums, dp);
        }

        int notTake = lis(index + 1, prevIndex, nums, dp);

        if (prevIndex != -1) {
            dp[index][prevIndex] = max(take, notTake);
            return dp[index][prevIndex];
        }

        return max(take, notTake);
    }
};