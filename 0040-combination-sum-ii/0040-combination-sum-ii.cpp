class Solution {
public:
    
    void dfs(vector<int>& candidates, int index, int target, vector<int>& path,  vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(path);
            return;
        }

        if (index >= candidates.size() || target < 0) return;

        // ✅ Include current element (only once, so move to index + 1)
        path.push_back(candidates[index]);
        dfs(candidates, index + 1, target - candidates[index], path, result);
        path.pop_back();

        // ✅ Exclude current element and skip all duplicates
        int nextIndex = index + 1;
        while (nextIndex < candidates.size() && candidates[nextIndex] == candidates[index])
            nextIndex++;  // skip over duplicates
            
        dfs(candidates, nextIndex, target, path, result);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // sort for deduplication
        
        vector<vector<int>> result;
        vector<int> path;
        
        dfs(candidates, 0, target, path, result);
        return result;
    }
};
