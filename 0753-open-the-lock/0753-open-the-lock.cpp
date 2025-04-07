class Solution {
public:
    // BFS - String Search State
    // Calculating Neighbors is the key aspect of this problem
    // which is done brilliantly
    int openLock(vector<string>& deadends, string target) {

        unordered_set<string> blockingSet(deadends.begin(), deadends.end());
        unordered_set<string> visited;

        if (blockingSet.count("0000"))
            return -1;

        queue<pair<string, int>> q;
        q.emplace("0000", 0);
        visited.insert("0000");

        while (!q.empty()) {
            auto [current, turns] = q.front();
            q.pop();

            if (current == target)
                return turns;

            // Neighbors
            for (int i = 0; i < 4; i++) {
                char c = current[i];

                current[i] = (((c - '0') + 1) % 10) + '0';

                if (!visited.count(current) && !blockingSet.count(current)) {
                    visited.insert(current);
                    q.emplace(current, turns + 1);
                }

                current[i] = (((c - '0') + 9) % 10) + '0';

                if (visited.count(current) == 0 &&
                    blockingSet.count(current) == 0) {
                    visited.insert(current);
                    q.emplace(current, turns + 1);
                }

                current[i] = c;
            }
        }

        return -1;
    }
};