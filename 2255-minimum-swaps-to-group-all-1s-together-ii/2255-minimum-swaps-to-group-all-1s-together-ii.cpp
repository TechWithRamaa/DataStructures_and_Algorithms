class Solution {
public:
    // Approach 1
    // name - Copy Trick 
    // Extending the circular nums array 
    // To make the given cirucular array into a linear array
    int minSwaps(vector<int>& nums) {
        vector<int> extended = nums;
        extended.insert(extended.end(), nums.begin(), nums.end());

        // detemining the window size
        int countOnes = count(nums.begin(), nums.end(), 1);

        int minSwaps = INT_MAX, countZeroes = 0;

        for(int i = 0; i < extended.size(); i++) {

            // outgoing zero
            if(i >= countOnes && extended[i - countOnes] == 0) 
                countZeroes--;

            // incoming zero
            if(extended[i] == 0) 
                countZeroes++;
            
            // updating optimized result
            if(i >= countOnes)
                minSwaps = min(minSwaps, countZeroes);
        }

        return minSwaps;
    }

    // Approach 2
    // Modulo Indexing
    // Very memory efficient
    int minSwaps2(vector<int>& nums) {
        return 0;
    }
};