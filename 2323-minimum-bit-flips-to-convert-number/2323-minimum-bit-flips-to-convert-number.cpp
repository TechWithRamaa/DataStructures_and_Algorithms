class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = start ^ goal; // XOR to find differing bits
        int count = 0;

        while (x > 0) {
            count += (x & 1); // Check last bit
            x >>= 1;          // Right shift to process next bit
        }

        return count;
    }
};