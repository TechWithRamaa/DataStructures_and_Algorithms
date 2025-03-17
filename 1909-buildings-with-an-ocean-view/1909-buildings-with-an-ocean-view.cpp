class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int N = heights.size();
        vector<int> result;

        int tallerBuilding = heights[N - 1];
        result.push_back(N - 1);
        for(int i = N - 2; i >= 0; i--) {
            if(tallerBuilding < heights[i]) {
                result.push_back(i);
                tallerBuilding = heights[i];
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};