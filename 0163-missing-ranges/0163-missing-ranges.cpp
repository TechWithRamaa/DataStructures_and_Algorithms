class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> result;
        
        // if(nums.empty()) {
        //     result.push_back({lower, upper});
        //     return result;
        // } => this case is covered by the below logic
        
        nums.insert(nums.begin(), lower - 1);
        nums.push_back(upper + 1);
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] - nums[i-1] > 1) {
                result.push_back({nums[i-1] + 1, nums[i] - 1});
            }
        }
                                 
        return result;
    }
};