class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int N = mat.size();
        int M = mat[0].size();
        
        vector<vector<int>> width(N, vector<int>(M, 0));
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(mat[i][j] == 1) {
                    width[i][j] = (j == 0) ? 1 : (width[i][j - 1] + 1);
                } 
            }
        }
        
        int count = 0;
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(mat[i][j] == 1) {
                    int minWidth = width[i][j];
                    
                    for(int k = i; k >= 0; k--) {
                        minWidth = min(minWidth, width[k][j]);
                        
                        if(minWidth == 0)
                            break;
                        
                        count += minWidth;
                    }
                }
            }
        }
        
        return count;
    }
};