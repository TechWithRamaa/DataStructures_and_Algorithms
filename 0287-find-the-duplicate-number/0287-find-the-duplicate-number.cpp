class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        if(nums.size() == 2) {
            if(nums[0] == nums[1]) {
                return nums[0];
            }
        }

        for(int i = 1; i <= nums.size() - 1; i++) {
            if(nums[i] == nums[i-1]) {
                return nums[i-1];
            }
        }

        return -1;
    }
};