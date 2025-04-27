class Solution {
public:
    // Finding Neighbors using Binar Search 
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        map<int, set<int>> rows, cols;

        // Group all buildings into rows and columns
        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            rows[x].insert(y);
            cols[y].insert(x);
        }

        int count = 0;

        for (auto& b : buildings) {
            int x = b[0], y = b[1];

            // Left: smaller y in same row
            auto itL = rows[x].lower_bound(y);
            bool hasLeft = (itL != rows[x].begin()); // means y is not the first one in the

            // Right: larger y in same row
            auto itR = rows[x].upper_bound(y);
            bool hasRight = (itR != rows[x].end());

            // Up: smaller x in same column
            auto itU = cols[y].lower_bound(x);
            bool hasUp = (itU != cols[y].begin());

            // Down: larger x in same column
            auto itD = cols[y].upper_bound(x);
            bool hasDown = (itD != cols[y].end());

            if (hasLeft && hasRight && hasUp && hasDown) {
                count++;
            }
        }

        return count;
    }
};