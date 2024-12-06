class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int M = matrix.size();
        int N = matrix[0].size();
        int subMatrixcount = 0;

        for (int r1 = 0; r1 < M; r1++) {
            vector<int> colSum(N, 0); 
            
            for (int r2 = r1; r2 < M; r2++) {
                
                for (int c = 0; c < N; c++) 
                    colSum[c] += matrix[r2][c];
                

                unordered_map<int, int> prefixSumCount;
                prefixSumCount[0] = 1; 
                int runningSum = 0;

                for (int sum : colSum) {
                    runningSum += sum;
                    if (prefixSumCount.find(runningSum - target) != prefixSumCount.end()) 
                        subMatrixcount += prefixSumCount[runningSum - target];
                    
                    prefixSumCount[runningSum]++;
                }
            }
        }

        return subMatrixcount;
    }
};