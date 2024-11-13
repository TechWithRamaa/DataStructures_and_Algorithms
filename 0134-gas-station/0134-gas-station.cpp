class Solution {
public:
    /*
     if total gas is greater than or equal to total cost, 1 circular journey can be completed
     so we are calculating total gas and total cost along the journey
     if total cost exceeds total gas, then journey can't be completed
     this intuition will determine if circular jouney is possible for the given set of inputs
    */
    
    /*
     inorder to know the starting point, we need to try starting from different gas stations
     at each station, we calculate tank by subtracting cost from available gas
     at any point, if tank becomes negative, we can reset the tank and start from next station 
     this intuition will identify the starting gas station.
     but it wont give the entire path which s not the current scope of the problem
    */

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