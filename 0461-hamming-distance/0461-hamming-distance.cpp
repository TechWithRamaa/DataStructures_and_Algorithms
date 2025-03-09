class Solution {
public:
    int hammingDistance1(int x, int y) {
        int count = 0;
        int xorV = x ^ y;

        // Hamming Weight logic
        while(xorV > 0) {
            count += xorV & 1;
            xorV = xorV >> 1;
        }

        return count;
    }

    int hammingDistance(int x, int y) {
        int count = 0;
        int xorV = x ^ y;

        // Hamming Weight logic
        while(xorV > 0) {
            int t = xorV - 1;
            xorV = xorV & t;
            count++;
        }

        return count;
    }
};