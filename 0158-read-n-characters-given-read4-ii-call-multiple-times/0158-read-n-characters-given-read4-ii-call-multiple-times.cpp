/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
private:
    char lastBuff[4];
    int lastBuffCnt = 0;
    int lastReadInd = 0;

public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char* buf, int n) {
        int totalRead = 0;

        while (totalRead < n) {
            // need a fresh buffer
            if (lastBuffCnt == lastReadInd) {
                lastBuffCnt = read4(lastBuff);
                lastReadInd = 0;
            }

            // eof reached
            if (lastBuffCnt == 0)
                break;
            
            // copy either from old buffer if left over is there or new buffer
            // ensuring totalRead < n always
            while (lastReadInd < lastBuffCnt && totalRead < n) {
                buf[totalRead++] = lastBuff[lastReadInd++];
            }
        }
        return totalRead;
    }
};