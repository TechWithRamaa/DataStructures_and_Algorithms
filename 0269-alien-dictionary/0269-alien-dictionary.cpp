class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> inDegree;

        int N = words.size();

        // unique characters are identified as nodes & initialized as 0
        for (const auto& current : words) {
            for (const auto& ch : current)
                inDegree[ch] = 0;
        }

        // graph (adjacency list) and inDegree map is constructed
        for (int i = 0; i < N - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];

            int minLen = min(w1.length(), w2.length());

            bool connectionFound = false;

            for (int j = 0; j < minLen; j++) {
                if (w1[j] != w2[j]) {
                    if (!graph[w1[j]].count(w2[j])) {
                        graph[w1[j]].insert(w2[j]);
                        inDegree[w2[j]]++;
                    }
                    connectionFound = true;
                    break;
                }
            }

            // invalid ordering given in input, so return ""
            if (!connectionFound && w1.length() > w2.length())
                return "";
        }

        // Topological sort logic starts
        queue<char> q;
        for (auto [key, value] : inDegree) {
            if (value == 0)
                q.push(key);
        }

        // BFS starts
        string lexOrder;
        while (!q.empty()) {
            auto alphabet = q.front();
            q.pop();

            lexOrder += alphabet;

            for (auto& neighbor : graph[alphabet]) {
                inDegree[neighbor]--;

                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return lexOrder.size() < inDegree.size() ? "" : lexOrder;
    }
};