class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> compressed;
        compressed.push_back(nums[0]);

        // Step 1: Compress by removing consecutive duplicates / De-duplication
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1]) {
                compressed.push_back(nums[i]);
            }
        }

        int count = 0;

        // Step 2: Check for hill or valley
        for (int i = 1; i < compressed.size() - 1; i++) {
            if ((compressed[i] > compressed[i-1] && compressed[i] > compressed[i+1]) ||
                (compressed[i] < compressed[i-1] && compressed[i] < compressed[i+1])) {
                count++;
            }
        }

        return count;
    }
};
