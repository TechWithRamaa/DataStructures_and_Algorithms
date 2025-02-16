class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int startingPosition = -1, lastPosition = -1;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                if(startingPosition == -1) 
                    startingPosition = i; 
                lastPosition = i;
            }
        }
        
        return {startingPosition, lastPosition};
    }
};