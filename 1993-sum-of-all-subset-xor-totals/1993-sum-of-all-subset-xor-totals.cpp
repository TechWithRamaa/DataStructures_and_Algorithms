class Solution {
public:
    int subsetXORSum1(vector<int>& nums) {
        int orAll = 0;
        for (int num : nums) {
            orAll |= num;
        }
        return orAll * (1 << (nums.size() - 1));
    }

    int subsetXORSum(vector<int>& nums) {
        int currXor = 0, total = 0;
        dfs(nums, 0, currXor, total);

        return total;
    }

private:
    void dfs(vector<int>& nums, int i, int currXor, int &total) {
        if (i == nums.size()) {
            total += currXor;
            return;
        }
        dfs(nums, i + 1, currXor ^ nums[i], total);
        dfs(nums, i + 1, currXor, total);
    }
};