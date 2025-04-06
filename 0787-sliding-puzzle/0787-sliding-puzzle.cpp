class Solution {
public:
    /*
    BFS over string-encoded state space
    Note down the state keyword in the problem statement

    \U0001f9e0 Common Concepts Across These:
    
    1) Use BFS for shortest path in unweighted transformations.
    2) Represent the state compactly: string, array, bitmask.
    3) Maintain a visited set to avoid cycles.
    4) Swap, change characters, or mutate to get next states.
    5) Stop BFS when you reach the goal state.

    */
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