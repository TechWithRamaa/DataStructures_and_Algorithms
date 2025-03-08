class Solution {
public:
    int climbStairs(int n) {
        int noOfWays = 0;

        if (n == 1 || n == 2) 
            return n;
        
        int last = 2, secondLast = 1;

        for(int i = 3; i <= n; i++) {
            noOfWays = last + secondLast;
            secondLast = last;
            last = noOfWays;
        }

        return noOfWays;
    }
};