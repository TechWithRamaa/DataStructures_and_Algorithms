class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        for (int divisor = 5; n / divisor > 0; divisor *= 5) {
            count += n / divisor;
        }
        return count;
    }
};