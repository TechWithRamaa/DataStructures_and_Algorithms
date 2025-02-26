class Solution {
public:
    // BruteForce using substr
    // TC ~ O ( n * m )
    int strStr3(string haystack, string needle) {
        int n = haystack.length(), m = needle.length();

        for(int i = 0; i <= n - m; i++) {
            if(haystack.substr(i, m) == needle) {
                return i;
            }
        }

        return -1;
    }
    
    // BruteForce using TwoPointer
    // TC ~ O ( n * m )
    int strStr(string hayback, string needle) {
        int n = hayback.length(), m = needle.length();
        int left = 0;

        while(left <= n - m) {
            int right = 0;
            while(right < m && hayback[left + right] == needle[right]) {
                right++;
            }

            if(right == m) {
                return left;
            }

            left++;
        }

        return -1;
    }

};