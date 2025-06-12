class Solution {
public:
    // Optimized approach
    // BitMasking 
    
    /*
    Each number from 0 to 2^n - 1 (bitmask) represents a unique subset, 
    where the i-th bit tells whether to include nums[i] in the subset.
    
    We loop through each bit of the mask and include elements where the bit is set (1).
    */
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;

        for (int mask = 0; mask < (1 << n); ++mask) {
            vector<int> subset;

            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }

            result.push_back(subset);
        }

        return result;
    }

    vector<vector<int>> subsets1(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;

        subsets(0, current, result, nums);

        return result;
    }

private:
    // Approach 1 -> Recursion
    void subsets1(int index, vector<int>& current, vector<vector<int>>& result,
                  vector<int>& nums) {
        if (index == nums.size()) {
            result.push_back(current);
            return;
        }

        current.push_back(nums[index]);
        subsets(index + 1, current, result, nums);

        current.pop_back();

        subsets(index + 1, current, result, nums);
    }

    // Approach 2 -> Recursion but odered from shorter to bigger subsets
    void subsets(int index, vector<int>& current, vector<vector<int>>& result,
                 vector<int>& nums) {

        result.push_back(current);

        for (int i = index; i < nums.size(); i++) {
            current.push_back(nums[i]);
            subsets(i + 1, current, result, nums);
            current.pop_back();
        }
    }
};