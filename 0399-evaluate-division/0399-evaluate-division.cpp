class Solution {
public:
    // DFS helper function
    double dfs(string current, string target, unordered_set<string>& visited,
               unordered_map<string, vector<pair<string, double>>>& graph,
               double value) {
        if (current == target)
            return value;
        visited.insert(current);

        for (auto& [neighbor, weight] : graph[current]) {
            if (visited.count(neighbor))
                continue;
            double result =
                dfs(neighbor, target, visited, graph, value * weight);
            if (result != -1.0)
                return result;
        }
        return -1.0;
    }

    vector<double> calcEquation1(vector<vector<string>>& equations,
                                 vector<double>& values,
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

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        // Step 1: Build the graph
        unordered_map<string, vector<pair<string, double>>> graph;

        for (int i = 0; i < equations.size(); ++i) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];

            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0 / val});
        }

        // Step 2: Process each query using BFS
        vector<double> result;

        for (const auto& query : queries) {
            string src = query[0];
            string dest = query[1];

            if (graph.find(src) == graph.end() ||
                graph.find(dest) == graph.end()) {
                result.push_back(-1.0);
            } else {
                result.push_back(bfs(src, dest, graph));
            }
        }

        return result;
    }

private:
    double bfs(string src, string dest,
               unordered_map<string, vector<pair<string, double>>>& graph) {
        if (src == dest)
            return 1.0;

        unordered_set<string> visited;
        queue<pair<string, double>> q;
        q.push({src, 1.0});
        visited.insert(src);

        while (!q.empty()) {
            auto [node, product] = q.front();
            q.pop();

            for (const auto& [neighbor, weight] : graph[node]) {
                if (visited.count(neighbor))
                    continue;

                double nextProduct = product * weight;

                if (neighbor == dest)
                    return nextProduct;

                visited.insert(neighbor);
                q.push({neighbor, nextProduct});
            }
        }

        return -1.0; // no path found
    }
};
