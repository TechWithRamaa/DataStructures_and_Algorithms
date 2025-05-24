/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */


class Solution {
public:
    // Saddleback search
    // Tap into Monotoncity property to optimize the search speculate
    // Search space gets reduced to 2000 from 1 million
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> result;
        
        int x = 1, y = 1000;
        while(x <= 1000 && y >= 1) {
            int val = customfunction.f(x, y);
            
            if(val == z) {
                result.push_back({x, y});
                x++;
                y--;
            } else if (val < z) {
                x++;
            } else {
                y--;
            }
        }
        
        return result;
    }
};