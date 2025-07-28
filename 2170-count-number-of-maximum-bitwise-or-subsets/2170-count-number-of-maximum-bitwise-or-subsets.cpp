class Solution {
public:
    int count = 0;
    int maxOR = 0;

    void dfs(vector<int>& nums, int i, int currOR) {
        if (i == nums.size()) {
            if (currOR == maxOR) count++;
            return;
        }

        // Exclude nums[i]
        dfs(nums, i + 1, currOR);

        // Include nums[i]
        dfs(nums, i + 1, currOR | nums[i]);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        for (int x : nums) maxOR |= x;
        dfs(nums, 0, 0);
        return count;
    }
};
