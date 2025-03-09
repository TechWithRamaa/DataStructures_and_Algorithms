class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        
        while(n > 0) {
            count += (n & 1); // & 1 -> extracts the last bit
            n = n >> 1; // right shift by 1 bit or equivalent to divide by 2
        }
        
        return count;
    }
};