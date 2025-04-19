class Solution {
public:
    // DFS helper function
    double dfs(string current, string target, unordered_set<string>& visited,
               unordered_map<string, vector<pair<string, double>>>& graph, double value) {
        if (current == target) return value;
        visited.insert(current);

        for (auto& [neighbor, weight] : graph[current]) {
            if (visited.count(neighbor)) continue;
            double result = dfs(neighbor, target, visited, graph, value * weight);
            if (result != -1.0) return result;
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;

        // Build the graph
        for (int i = 0; i < equations.size(); ++i) {
            string a = equations[i][0], b = equations[i][1];
            double val = values[i];

            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0 / val});
        }

        vector<double> result;

        // Evaluate each query using DFS
        for (auto& query : queries) {
            string start = query[0], end = query[1];

            if (!graph.count(start) || !graph.count(end)) {
                result.push_back(-1.0);
                continue;
            }

            unordered_set<string> visited;
            double res = dfs(start, end, visited, graph, 1.0);
            result.push_back(res);
        }

        return result;
    }
};
