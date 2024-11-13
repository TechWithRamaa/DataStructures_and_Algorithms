class Solution {
public:
    string reverseWords(string s) {
        removeLeadingSpacesAndMultipleSpacesBtwnWords(s);
        std :: reverse(s.begin(), s.end());
        reverseIndividualWords(s);
        return s;
    }
private:
    void reverseIndividualWords(string &s) {
        int start = 0;
        for (int end = 0; end <= s.size(); ++end) {
            if (end == s.size() || s[end] == ' ') {
                std :: reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }
    }

    void removeLeadingSpacesAndMultipleSpacesBtwnWords(string &s) {
        const int N = s.size();
        int start = 0;

        // moves through leading spaces & stops at non-space characters
        while(start < N && s[start] == ' ') 
            start++;
        
        int i = 0;
        while(start < N) {
            if(s[start] != ' ') // shifting non-space characters
                s[i++] = s[start++];
            else {
                // eliminating multiple spaces between words
                while(start < N && s[start] == ' ') 
                    start++;
                // adds just 1 space for any multiple spaces
                if(start < N) s[i++] = ' ';
            }
        }

        s.resize(i); // eliminates trailing spaces
    }
};