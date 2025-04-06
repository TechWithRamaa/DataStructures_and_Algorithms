class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";

        for (auto& row : board) {
            for (int num : row)
                start += to_string(num);
        }

        string target = "123450";

        queue<pair<string, int>> q;
        unordered_set<string> visited;

        vector<vector<int>> neighbors = {{1, 3}, {0, 2, 4}, {1, 5},
                                         {0, 4}, {1, 3, 5}, {2, 4}};

        q.emplace(start, 0);
        visited.insert(start);

        while (!q.empty()) {
            auto [current, steps] = q.front();
            q.pop();

            if(current == target)
                return steps;

            int zerosPos = current.find('0');
            for (auto neighbor : neighbors[zerosPos]) {
                string next = current;
                swap(next[zerosPos], next[neighbor]);

                if(visited.count(next))
                    continue;
                
                visited.insert(next);
                q.emplace(next, steps + 1);
            }
        }

        return -1;
    }
};