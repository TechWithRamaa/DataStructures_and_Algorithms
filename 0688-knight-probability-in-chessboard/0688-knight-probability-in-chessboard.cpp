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