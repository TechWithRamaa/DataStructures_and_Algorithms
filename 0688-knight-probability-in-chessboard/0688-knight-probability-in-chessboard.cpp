/*
Knight Probability in Chessboard — Revision Notes

Optimized Idea: Use Top-Down DP with Memoization
Define a recursive function:
    dp(r, c, k) = probability that the knight remains on the board 
                     after making k moves starting from position (r, c)
Base Cases:
    If knight is off the board (r < 0 || r >= n || c < 0 || c >= n):
        ➤ Return 0.0 (probability is zero)

    If no moves left (k == 0) and knight is on board:
        ➤ Return 1.0 (safe ending)

Recursive Case:
    For each of the 8 knight moves:

        Move to (nr, nc) = (r + dx, c + dy)

        Recursively call: dp(nr, nc, k - 1)

        Accumulate the probabilities

        Average out the total:
            ➤ probability = sum of all 8 moves / 8.0

Memoization:
    Use a 3D DP table:

dp[n][n][k+1]
n = board size
k+1 = moves remaining

Cache results to avoid recomputation
*/

// Modeling with Recursion + State Compression
class Solution {
public:
    int N;
    vector<vector<int>> moves = {{-2, -1}, {-2, 1},
                                 {-1, -2}, {-1, 2}, 
                                 {1, -2}, {1, 2}, 
                                 {2, -1}, {2, 1}};
    
    double knightProbability(int n, int k, int row, int column) {
        N = n;
        vector<vector<vector<double>>> memo(n, vector<vector<double>>(n, vector<double>(k+1, -1)));
        
        return dfs(row, column, k, memo);
    }
private:
    
    double dfs(int row, int col, int k, vector<vector<vector<double>>>& memo) {
        if(row < 0 || row >= N || col < 0 || col >= N) 
            return 0.0; // off-board
        
        if(k == 0)
            return 1.0; // no moves left, still on board
        
        if(memo[row][col][k] != -1.0)
            return memo[row][col][k];
        
        double prob = 0.0;
        
        for(auto& move : moves) {
            int nr = row + move[0];
            int nc = col + move[1];
            
            prob += dfs(nr, nc, k-1, memo) / 8.0;
        }
        
        return memo[row][col][k] = prob;
    }
};