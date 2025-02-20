class Solution {
public:
    double myPow(double x, int n) {
        // Handle edge case where n is INT_MIN to avoid overflow
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double result = 1;
        while (N > 0) {
            if (N % 2 == 1) { // If n is odd
                result *= x;
            }
            x *= x; // Square the base
            N /= 2; // Reduce exponent
        }
        return result;
    }
};