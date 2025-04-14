class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long a = labs(dividend);
        long b = labs(divisor);
        long result = 0;

        while(a >= b) {
            long currentDivisor = b;
            long currentMultiples = 1;

            while((currentDivisor << 1) <= a) {
                currentDivisor = currentDivisor << 1;
                currentMultiples = currentMultiples << 1;
            }

            a -= currentDivisor;
            result += currentMultiples;
        }

        bool sameSign = (dividend > 0) == (divisor > 0);

        return sameSign ? result : (-result);
    }
};