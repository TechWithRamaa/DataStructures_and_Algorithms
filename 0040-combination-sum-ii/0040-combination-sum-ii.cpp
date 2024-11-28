class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, const int target) {
        vector<vector<int>> result;
        vector<int> combination;

        sort(candidates.begin(), candidates.end());

        unordered_map<string, vector<vector<int>>> memo;  
        combinationSum2(candidates, target, 0, combination, result, memo);

        return result;
    }

private:
    void combinationSum2(vector<int>& candidates, int target, int start, vector<int>& combination,
                         vector<vector<int>>& result, unordered_map<string, vector<vector<int>>> memo) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }

        string key = to_string(start) + "-" + to_string(target);
        if (memo.find(key) != memo.end()) {
            for (const auto& comb : memo[key]) {
                result.push_back(comb);
            }
            return;
        }

        for (int index = start; index < candidates.size(); index++) {
            if (index > start && candidates[index] == candidates[index-1])
                 continue;

            if (candidates[index] > target)
                break;
        
            combination.push_back(candidates[index]);
            combinationSum2(candidates, target - candidates[index], index + 1, combination, result, memo);

            combination.pop_back();
        }

         memo[key] = result;
    }
};