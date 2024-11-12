#include<algorithm>

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        vector<int> histogram(COLS, 0);
        int maxArea = 0;

        for(int i  = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
               histogram[j] = matrix[i][j] == '1' ? histogram[j] + 1 : 0;
            }
            maxArea = std::max(maxArea, largestRectangleArea(histogram));
        }
        return maxArea;
    }
private:
    int largestRectangleArea(vector<int> & histogram) {
        const int COLS = histogram.size();
        stack<int> s;
        int maxArea = 0;

        for(int i = 0; i <= COLS; i++) {
            while(!s.empty() && (i == COLS || histogram[s.top()] >= histogram[i])) {
                int height = histogram[s.top()];
                s.pop();

                int width;
                if(s.empty()) width = i;
                else width = i - s.top() - 1;

                maxArea = std :: max(maxArea, height * width);
            }
            s.push(i);
        }
        return maxArea;
    }
};