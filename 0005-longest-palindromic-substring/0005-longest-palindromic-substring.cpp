class Solution {
public:
    string longestPalindrome(string s) {
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
};