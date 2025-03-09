class Solution {
public:
    // Approach - Brian Kernighan’s Algorithm
    // TC ~ O ( log n ) 
    // Goes through only set bits
    int hammingWeight(int n) {
        int count = 0;

        while(n > 0) {
            int t = n - 1;
            n = n & t;
            count++;
        }

        return count;
    }

    // TC ~ O ( log n )
    // Approach - Goes through every bit
    // Hamming Weight is nothing but the count of set bits
    int hammingWeight1(int n) {
        int count = 0;
        
        while(n > 0) {
            count += (n & 1); // & 1 -> extracts the last bit
            n = n >> 1; // right shift by 1 bit or equivalent to divide by 2
        }
        
        return count;
    }
};