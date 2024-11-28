class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;

        subsets(nums, 0, current, result);

        return result;
    }
private:
   void subsets(const vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
        if(index >= nums.size()) {
            result.push_back(current);
            return;
        }

        // include
        current.push_back(nums[index]);
        subsets(nums, index + 1, current, result);

        current.pop_back();

        // exclude
        subsets(nums, index + 1, current, result);
    }
};