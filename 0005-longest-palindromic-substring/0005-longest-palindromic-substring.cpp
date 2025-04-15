class Solution {
public:
    // the question is on substring not a subsequence
    // therefore, this expanding from center holds only palindrome substrings

    // logic of expanding from center from  all possible positions
    // 2 pointer for checking if the current window is a palindrome or not
    // Approach - Expand around center, not DP
    // but this solution generate substrings everytime
    // there is a iterative solution that only generates string for maximum length
    string longestPalindrome1(string s) {
        string result = "";
        
        for(int i = 0; i < s.length(); i++) {
            string oddLengthPalindrome = getPalindromeExpandedFromCenter(s, i, i);
            if(oddLengthPalindrome.length() > result.length())
                result = oddLengthPalindrome;
            
            string evenLengthPalindrome = getPalindromeExpandedFromCenter(s, i, i + 1);
            if(evenLengthPalindrome.length() > result.length())
                result = evenLengthPalindrome;
        }
        return result;
    }
private:
    string getPalindromeExpandedFromCenter(string s, int start, int end) {
        while(start >= 0 && end < s.length() && s[start] == s[end]) {
            start--;
            end++;
        }
        
        return s.substr(start+1, end - start - 1);
    }
public:
    // Approach 2 
    // Expand around center - Simple * Intuitive
    string longestPalindrome(string s) {
        int start = 0, maxLen = 0;

        for(int center = 0; center < (2 * s.size() - 1); center++) {
            int left = center / 2;
            int right = left + (center % 2);

            while((left >= 0 && right < s.size()) && s[left] == s[right]) {
                if(maxLen <= (right - left + 1)) {
                    start = left;
                    maxLen = (right - left + 1);
                }
                left--;
                right++;
            }
        }

        return s.substr(start, maxLen);
    }
}; 