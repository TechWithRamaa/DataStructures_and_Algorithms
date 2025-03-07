class Solution {
public:
    // Approach 1
    // Hashset - A BruteForce
    // TC ~ O ( N ) ; SC ~ O ( N )
    int missingNumber1(vector<int>& nums) {
        int N = nums.size();
        // nums in the range 0 to N

        unordered_set<int> numSet;
        int start = 0;
        for (int i = 0; i <= N; i++) {
            numSet.insert(i);
        }

        for (auto num : nums) {
            numSet.erase(num);
        }

        return *numSet.begin();
    }

    // Approach 2
    // Sum Formula
    // TC ~ O ( N ); SC ~ O ( 1 )
    int missingNumber2(vector<int>& nums) {
        int N = nums.size();
        // nums in the range 0 to N

        int expectedSum = (N * (N + 1) / 2);
        int actualSum = accumulate(nums.begin(), nums.end(), 0);

        return expectedSum - actualSum;
    }

    // Approach 3
    // XOR (Highly rated)
    // TC ~ O ( N ); SC ~ O ( 1 )
    int missingNumber(vector<int>& nums) {
        int N = nums.size();
        // nums in the range 0 to N

        int xor1 = 0, xor2 = 0;

        for (int i = 0; i <= N; i++)
            xor1 ^= i;

        for (int num : nums)
            xor2 ^= num;

        return xor1 ^ xor2;
    }
};