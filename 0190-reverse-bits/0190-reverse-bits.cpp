class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;

        for(int i = 1; i <= 32; i++) {
            int lastBit = n & 1; // extracts last bit
            result = result << 1; // multiplies by 2 or left shift by 1 bit
            result = result | lastBit; // appends the extracted bit to result
            n = n >> 1; // divides the n by 2 or right shift by 1 bit
        }

        return result;
    }
};