class Solution {
public:
    int divide(int dividend, int divisor) {
        // Edge case: Handle overflow when dividend = INT_MIN and divisor = -1
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX; // Avoid overflow
        }

        // Track the sign of the quotient
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert both numbers to negatives (to avoid overflow)
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long quotient = 0;

        while (a >= b) {
            long long temp = b, multiple = 1;
            // Find the largest multiple of divisor that fits within the dividend
            while ((temp << 1) <= a) {
                temp <<= 1;
                multiple <<= 1;
            }
            a -= temp;
            quotient += multiple;
        }

        return negative ? -quotient : quotient;  
    }
};