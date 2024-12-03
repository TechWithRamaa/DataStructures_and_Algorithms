class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 0) return {};

        // Sort the input array
        sort(nums.begin(), nums.end());

        // dp[i] will store the size of the largest divisible subset ending at index i
        vector<int> dp(n, 1);
        // parent[i] will store the index of the previous element in the largest subset ending at i
        vector<int> parent(n, -1);

        int maxSubsetSize = 1, maxSubsetIndex = 0;

        // Fill the dp array
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }

            // Track the maximum subset size and its index
            if (dp[i] > maxSubsetSize) {
                maxSubsetSize = dp[i];
                maxSubsetIndex = i;
            }
        }

        // Reconstruct the largest subset
        vector<int> result;
        while (maxSubsetIndex != -1) {
            result.push_back(nums[maxSubsetIndex]);
            maxSubsetIndex = parent[maxSubsetIndex];
        }

        // The result needs to be reversed to be in ascending order
        reverse(result.begin(), result.end());
        return result;
    }
};
