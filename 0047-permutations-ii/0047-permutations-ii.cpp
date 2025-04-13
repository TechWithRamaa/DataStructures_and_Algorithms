class Solution {
public:
    // Approach - Sorting + In-place swap + Backtracking
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());
        permuteUnique(result, nums, 0);

        return result;
    }

private:
    void permuteUnique(vector<vector<int>>& result,
                       vector<int>& nums, int start) {
        if(start == nums.size()) {
            result.push_back(nums);
            return;
        }

        unordered_set<int> used;

        for (int i = start; i < nums.size(); i++) {
            if(used.count(nums[i]))
                continue;

            used.insert(nums[i]);
            swap(nums[i], nums[start]); // make a choice
            
            permuteUnique(result, nums, start + 1); // explore
            
            swap(nums[i], nums[start]); // undo
        }
    }
};