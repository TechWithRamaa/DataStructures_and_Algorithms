class Solution {
public:
    // Approach 1 
    // Most optimal // Mathematical approach 
    // TC ~ O ( 1 )
    long long coloredCells(int n) {
        return 1LL * n * n + 1LL * (n - 1) * (n - 1);
    }

    // Approach 2 
    // BruteForce // BFS with a SET instead of a QUEUE
    // TC ~ O ( n ^ 2 ) && SC ~ O ( n ^ 2)
    // Slow for larger N
    long long coloredCells2(int n) {
        set<pair<int, int>> colored; // set helps us maintain distinct cells
        colored.insert({0, 0});  // Start with one colored cell

        for (int t = 1; t < n; t++) {
            set<pair<int, int>> newColored;
            for (auto [x, y] : colored) {
                newColored.insert({x + 1, y});
                newColored.insert({x - 1, y});
                newColored.insert({x, y + 1});
                newColored.insert({x, y - 1});
            }
            for (auto cell : newColored) {
                colored.insert(cell);
            }
        }

        return colored.size();
    }

};