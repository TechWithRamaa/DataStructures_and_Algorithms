class Solution {
public:
    // Approach 1
    // name - Copy Trick
    // Extending the circular nums array
    // To make the given cirucular array into a linear array
    // Fixed Sliding Window - Classic template
    int minSwaps1(vector<int>& nums) {

        // detemining the window size
        int countOnes = count(nums.begin(), nums.end(), 1);

        vector<int> extended = nums;
        extended.insert(extended.end(), nums.begin(), nums.end());

        int countZeroes =
            count(extended.begin(), extended.begin() + countOnes, 0);

        int minSwaps = countZeroes;

        for (int i = countOnes; i < extended.size(); i++) {

            // outgoing zero
            if (extended[i - countOnes] == 0)
                countZeroes--;

            // incoming zero
            if (extended[i] == 0)
                countZeroes++;

            // updating optimized result
            minSwaps = min(minSwaps, countZeroes);
        }

        return minSwaps;
    }

    // Approach 1
    // name - Copy Trick
    // Extending the circular nums array
    // To make the given cirucular array into a linear array
    // Fixed Sliding Window - Hybrid (template almost like a Dynamic Sliding
    // Window)
    int minSwaps2(vector<int>& nums) {
        vector<int> extended = nums;
        extended.insert(extended.end(), nums.begin(), nums.end());

        // detemining the window size
        int countOnes = count(nums.begin(), nums.end(), 1);

        int minSwaps = INT_MAX, countZeroes = 0;

        for (int i = 0; i < extended.size(); i++) {

            // outgoing zero
            if (i >= countOnes && extended[i - countOnes] == 0)
                countZeroes--;

            // incoming zero
            if (extended[i] == 0)
                countZeroes++;

            // updating optimized result
            if (i >= countOnes)
                minSwaps = min(minSwaps, countZeroes);
        }

        return minSwaps;
    }

    // Approach 2
    // Modulo Indexing
    // Very memory efficient
    // Fixed Sliding Window
    int minSwaps(vector<int>& nums) {
        // determining the window size
        int countOnes = count(nums.begin(), nums.end(), 1);

        // no of zeros in first fixed window
        int countZeroes = count(nums.begin(), nums.begin() + countOnes, 0);

        int minSwaps = countZeroes;
        int N = nums.size();
        
        // second window starts from 1
        for (int i = 1; i < N; i++) {

            int outIdx = (i - 1) % N;
            int inIdx = (i + countOnes - 1) % N;

            // outgoing element
            if (nums[outIdx] == 0)
                countZeroes--;

            // incoming element
            if (nums[inIdx] == 0)
                countZeroes++;

            minSwaps = min(minSwaps, countZeroes);
        }

        return minSwaps;
    }
};