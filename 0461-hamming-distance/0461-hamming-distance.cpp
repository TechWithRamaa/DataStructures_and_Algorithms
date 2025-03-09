class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        int xorV = x ^ y;

        while(xorV > 0) {
            count += xorV & 1;
            xorV = xorV >> 1;
        }

        return count;
    }
};