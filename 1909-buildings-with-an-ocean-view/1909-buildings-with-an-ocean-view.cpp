class Solution {
public:
    // Although BruteForce exists & it takes TC ~ O ( n ^ 2)
    // We go with a Greedy Approach in 1 pass
    
    // Traverse from right to left 
    // Add the indices to result if no taller building exists to its right
    // keep updating the taller building in each iteration
    // finally return the reversed list as per the expectations of the problem

    // TC ~ O ( n + n [reverse] ) ; SC ~ O ( 1 )
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