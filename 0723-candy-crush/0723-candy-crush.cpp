class Solution {
public:
    // greedy simulation until stable
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int M = board.size(), N = board[0].size();
        bool changed = true;

        while(changed) {
            changed = false; 

            // Mark candies
            for(int i = 0; i < M; i++) {
                for(int j = 0; j < N; j++) {
                    int val = abs(board[i][j]);
                    
                    if(val == 0)
                        continue;
                    
                    // check for minimum 3 cells & extend further & mark it
                    if(j + 2 < N && abs(board[i][j + 1]) == val && abs(board[i][j + 2]) == val) {
                        int k = j;
                        
                        // marking them for crushing / dropping
                        while(k < N && abs(board[i][k]) == val)
                            board[i][k++] = -val;

                        changed = true; 
                    }

                    // check for minimum 3 cells & extend further & mark it
                    if(i + 2 < M && abs(board[i + 1][j]) == val && abs(board[i + 2][j]) == val) {
                        int k = i;
                        
                        // marking them for crushing / dropping
                        while(k < M && abs(board[k][j]) == val)
                            board[k++][j] = -val;

                        changed = true; 
                    }
                }
            }
            
            // crush it
            for(int i = 0; i < M; i++) {
                for(int j = 0; j < N; j++) {
                    if(board[i][j] < 0)
                        board[i][j] = 0;
                }
            }

            // gravity - core technique => move non-zero elements to the front 
            for(int j = 0; j < N; j++) {
                int idx = M - 1; // write pointer

                for(int i = M - 1; i >= 0; i--) {
                    if(board[i][j] > 0) 
                        board[idx--][j] = board[i][j];
                }

                // mark the rest of the fields zero
                while(idx >= 0) 
                    board[idx--][j] = 0; 
            }
        }

        return board;
    }
};