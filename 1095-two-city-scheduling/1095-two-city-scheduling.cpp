class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](const vector<int> &a, const vector<int> &b){
            return a[0] - a[1] < b[0] - b[1];
        });

        int totalCost = 0, N = costs.size(), GROUP_SIZE = N / 2;

        for(int i = 0; i < N; i++) {
            if(i < GROUP_SIZE)
                totalCost += costs[i][0]; // city A
            else 
                totalCost += costs[i][1];
        }

        return totalCost;
    }
};