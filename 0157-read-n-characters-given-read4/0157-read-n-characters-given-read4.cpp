/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        char temp[4];
        int soFarRead = 0;

        while(soFarRead < n) {
            int count = read4(temp);
            int toCopy = min(count, n - soFarRead);

            for(int i = 0; i < toCopy; i++) {
                buf[soFarRead++] = temp[i]; 
            }

            if(count < 4) 
                break;
        }

         return soFarRead;
    }
};