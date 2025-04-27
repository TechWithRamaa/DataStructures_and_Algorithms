class Solution {
public:
    bool dfs(int mask, int mod, vector<int>& nums, int k, vector<int>& pow10, vector<vector<int>>& dp, vector<int>& path) {
        int n = nums.size();
        if (mask == (1 << n) - 1) {
            return mod == 0;
        }
        if (dp[mask][mod] != -1) {
            return false;
        }

        for (int i = 0; i < n; ++i) {
            if (!(mask & (1 << i))) { // if i-th number not picked yet
                int len = to_string(nums[i]).size();
                int newMod = (mod * pow10[len] + nums[i]) % k;
                path.push_back(nums[i]);
                if (dfs(mask | (1 << i), newMod, nums, k, pow10, dp, path)) {
                    return true;
                }
                path.pop_back();
            }
        }

        dp[mask][mod] = 0; // memoize as impossible
        return false;
    }

    vector<int> concatenatedDivisibility(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        vector<int> pow10(11, 1); // powers of 10 modulo k
        for (int i = 1; i <= 10; ++i) {
            pow10[i] = (pow10[i - 1] * 10) % k;
        }

        vector<vector<int>> dp(1 << n, vector<int>(k, -1)); // memoization table
        vector<int> path; // to store the final answer

        if (dfs(0, 0, nums, k, pow10, dp, path)) {
            return path;
        }
        return {}; // no valid permutation found
    }
};