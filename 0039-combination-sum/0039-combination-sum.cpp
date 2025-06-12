class Solution {
public:
    /*
    \U0001f538 You can memoize combinationSum, but it's rarely beneficial because each call depends on a unique path and index.
    \U0001f538 If the problem were to return count of combinations, or allow permutation-based reuse, then memoization would be more useful.
    */
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;

        combinationSum(0, current, result, candidates, target);

        return result;
    }

private:
    void combinationSum(int start, vector<int>& current, vector<vector<int>>& result,
                        vector<int>& candidates, int target) {
    
        if(target == 0) {
            result.push_back(current);
            return;
        }

        if(target < 0)
            return;
        
        for(int i = start; i < candidates.size(); i++) {
            current.push_back(candidates[i]);
            combinationSum(i, current, result, candidates, target - candidates[i]);
            current.pop_back();
        }

    }

};