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

    // some gyan
    // bit wise logic

    // flips all bits after left most set bit including itself => n - 1
    // which is equal to subtracting the decimal number by 1
    
    // extract the last set bit => & 1

    // divided the number by 2 => >> 1

    // gives differences btwn 2 numbers => x ^ y
};