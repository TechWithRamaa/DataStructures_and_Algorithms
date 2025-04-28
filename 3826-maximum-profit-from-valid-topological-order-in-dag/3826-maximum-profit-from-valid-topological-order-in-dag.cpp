class Solution {
private:
    int helper(int mask, int pos, vector<int>& inDegree, vector<vector<int>>& adj, vector<int>& score, vector<int>& dp, int n) {
        // all nodes processed
        if (mask == (1 << n) - 1) 
            return 0; 

        if (dp[mask] != -1) return dp[mask];
        
        int res = 0;
        
        for (int i = 0; i < n; i++) {
            // if node i not picked yet and indegree 0
            if ((mask & (1 << i)) == 0 && inDegree[i] == 0) {
                for (int ng : adj[i]) {
                    inDegree[ng]--;
                }
                
                int val = pos * score[i] + helper(mask | (1 << i), pos + 1, inDegree, adj, score, dp, n);
                res = max(res, val);
                
                for (int ng : adj[i]) {
                    inDegree[ng]++;
                }
            }
        }
        
        return dp[mask] = res;
    }
    
public:
    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);
        
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            inDegree[e[1]]++;
        }
        
        vector<int> dp(1 << n, -1);
        
        return helper(0, 1, inDegree, adj, score, dp, n);
    }
};
