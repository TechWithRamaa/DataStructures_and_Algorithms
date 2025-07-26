class Solution {
public:
    // BruteForce using substr
    // TC ~ O ( n * m )
    int strStr3(string haystack, string needle) {
        int n = haystack.length(), m = needle.length();

        for (int i = 0; i <= n - m; i++) {
            if (haystack.substr(i, m) == needle) {
                return i;
            }
        }

        return -1;
    }

    // BruteForce using TwoPointer
    // TC ~ O ( n * m )
    int strStrB(string hayback, string needle) {
        int n = hayback.length(), m = needle.length();
        int i = 0;

        while (i <= n - m) {
            int end = 0; // always start end from 0 at each iteration // end
                         // tracks indices over needle

            // fix i as the starting point & expand end
            while (end < m && hayback[i + end] == needle[end]) {
                end++; // expand the matching part further
            }

            // if end exactly becomes the length of substring, then match found
            if (end == m) {
                return i;
            }

            i++; // otherwise try from next position onwards again
        }

        return -1;
    }

    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        if (m == 0)
            return 0;

        // Build LPS
        vector<int> lps(m, 0);
        int len = 0; // length of the previous longest prefix suffix
        for (int i = 1; i < m;) {
            if (needle[i] == needle[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0)
                    len = lps[len - 1];
                else
                    lps[i++] = 0;
            }
        }

        // KMP Search
        int i = 0, j = 0;
        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++, j++;
            }
            if (j == m)
                return i - j;
            else if (i < n && haystack[i] != needle[j]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        return -1;
    }
};