class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int subMatrixcount = 0;

        for (int r1 = 0; r1 < rows; ++r1) {
            vector<int> colSum(cols, 0); 
            
            for (int r2 = r1; r2 < rows; ++r2) {
                
                for (int c = 0; c < cols; ++c) 
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