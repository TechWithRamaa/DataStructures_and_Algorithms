class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       int totalGas = 0, totalCost = 0, currentTank = 0, startingStation = 0;

       for(int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];

            currentTank += gas[i] - cost[i];
            if(currentTank < 0) {
                startingStation = i + 1;
                currentTank = 0;
            } 
       } 

       return totalGas >= totalCost ? startingStation : -1;
    }
};