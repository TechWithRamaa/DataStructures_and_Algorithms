class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 2) 
            return min(cost[0], cost[1]);
        
        int last = cost[1], secondLast = cost[0];
        for(int i = 2; i < cost.size(); i++) {
            int current = cost[i] + min(last, secondLast);
            secondLast = last;
            last = current;
        }

        return min(secondLast, last);
    }
};