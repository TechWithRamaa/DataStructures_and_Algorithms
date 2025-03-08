class Solution {
public:
    /* Problem Statement Restated
    Essentially, the problem is asking:

    Find a sliding window of length k in the string
    where converting all white blocks inside that window
    to black requires the fewest changes.
    */

    int minimumRecolors(string blocks, int k) {
        int whiteCount = 0;
        int minimumWhiteInAWindow = 0;

        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                whiteCount += 1;
            }
        }

        minimumWhiteInAWindow = whiteCount;

        for (int end = k; end < blocks.length(); end++) {
            if (blocks[end - k] == 'W') {
                whiteCount--;
            }

            if (blocks[end] == 'W') {
                whiteCount++;
            }

            minimumWhiteInAWindow = min(minimumWhiteInAWindow, whiteCount);
        }

        return minimumWhiteInAWindow;
    }
};