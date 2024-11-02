#include <algorithm>

class Solution {
public:
    int minimumTotal(const vector<vector<int>>& triangle) {
        const int TRIANGLE_SIZE = triangle.size();
        const int INITIAL_VALUE = -100505;

        vector<vector<int>> cache(TRIANGLE_SIZE);

        for(int i = 0; i < TRIANGLE_SIZE; i++){
            cache[i] = vector<int>(triangle[i].size(), INITIAL_VALUE);
        }

        return minimumTotal(triangle, cache, TRIANGLE_SIZE, 0, 0); 
    }

    int minimumTotal(const vector<vector<int>>& triangle, vector<vector<int>>& cache, const int TRIANGLE_SIZE, int rowIndex, int elementIndex) {
        if(rowIndex == TRIANGLE_SIZE) 
            return 0;

        if(cache[rowIndex][elementIndex] != -100505) 
            return cache[rowIndex][elementIndex];
        
        int leftPathSum = triangle[rowIndex][elementIndex] + minimumTotal(triangle, cache, TRIANGLE_SIZE, rowIndex + 1, elementIndex);
        int rightPathSum = triangle[rowIndex][elementIndex] + minimumTotal(triangle, cache, TRIANGLE_SIZE, rowIndex + 1, elementIndex + 1);

        return cache[rowIndex][elementIndex] = std::min(leftPathSum, rightPathSum); 
    }
};