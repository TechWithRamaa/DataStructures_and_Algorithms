class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int sum = a ^ b;    // Gives the sum of bits without carry
            int carry = (a & b) << 1;  // Computes the carry that needs to be added in the next iteration.

            a = sum;
            b = carry;
        }
        return a; 
    }
};