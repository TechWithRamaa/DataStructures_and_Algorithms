class Solution {
public:
     int trap(vector<int>& height) {
        stack<int> elevations;
        int waterTrapped = 0;
        
        // find the dip
        // find the left wall and right wall
        for(int i = 0; i < height.size(); i++) {
            while(!elevations.empty() && height[elevations.top()] < height[i]) {
                int smallerElevationIndex = elevations.top();
                elevations.pop();

                if(elevations.empty()) {
                    break; // no left boundard exists
                }
                int rightBoudaryIndex = i;
                int leftBoundaryIndex = elevations.top();
                int trappingHeight = min(height[rightBoudaryIndex], height[leftBoundaryIndex]) - height[smallerElevationIndex];
                // the extra variables can be avoided by using it directly

                int width = rightBoudaryIndex - leftBoundaryIndex - 1;

                waterTrapped += width * trappingHeight;
            }
            elevations.push(i);
        }

        return waterTrapped;
    }
};