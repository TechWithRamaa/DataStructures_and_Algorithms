class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = conversions.size() + 1;
        unordered_map<int, vector<pair<int, int>>> g(n);
        for (auto& v : conversions) {
            g[v[0]].push_back({v[1], v[2]});
        }

        vector<int> ans(n, 0);
        const int mod = 1e9 + 7;
        queue<int> q;
        ans[0] = 1;
        q.push(0);

        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (auto& [y, z] : g[x]) {
                ans[y] = (1LL * ans[x] * z) % mod;
                q.push(y);
            }
        }

        return ans;
    }
};