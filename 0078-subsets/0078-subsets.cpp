class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;

        subsets(0, current, result, nums);

        return result;
    }

private:
    void subsets(int index, vector<int>& current,
                                vector<vector<int>>& result,
                                vector<int>& nums) {
        if(index == nums.size()) {
            result.push_back(current);
            return;
        }

        current.push_back(nums[index]);
        subsets(index + 1, current, result, nums);
        
        current.pop_back();

        subsets(index+1, current, result, nums);
    }
};