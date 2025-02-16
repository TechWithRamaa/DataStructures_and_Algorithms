class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permute(0, result, nums);
        return result;
    }
private:
    void permute(int start, vector<vector<int>>& result, vector<int>& nums) {
        if(start == nums.size()) {
            result.push_back(nums);
            return;
        }

        for(int i = start; i < nums.size(); i++) {
            swap(nums[i], nums[start]);
            permute(start + 1, result, nums);
            swap(nums[i], nums[start]);
        }
    }
};