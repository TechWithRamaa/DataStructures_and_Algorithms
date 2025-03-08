class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int whiteCount = 0;
        int minimumWhiteInAWindow = 0;

        for(int i = 0; i < k; i++) {
            if(blocks[i] == 'W') {
                whiteCount += 1; 
            }
        }

        minimumWhiteInAWindow = whiteCount;
        int start = 0;
        for(int end = k; end < blocks.length(); end++) {
            if(blocks[start] == 'W') {
                    whiteCount--;
            }

            if(blocks[end] == 'W') {
                whiteCount++;
            }

            minimumWhiteInAWindow = min(minimumWhiteInAWindow, whiteCount);
            start++;
        }

        return minimumWhiteInAWindow;
    }
};