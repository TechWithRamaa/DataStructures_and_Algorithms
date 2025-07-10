class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });

        int arrows = 1;
        int lastPoint = points[0][1];

        // Grredy Simulation instead of actual overlapping
        for(const auto& v : points) {
            if(v[0] > lastPoint) {
                arrows++;
                lastPoint = v[1];
            }    
        }

        return arrows;
    }
};