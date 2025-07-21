class Solution {
public:
    // Expand Around Centers
    /*
    A palindrome is defined by its center.
    Each character can be the center of an odd-length palindrome.
    Each pair of characters can be the center of an even-length palindrome.

    Algorithm:-

    Iterate over each index i in the string.
    Expand around i (odd-length palindromes).
    Expand around i and i+1 (even-length palindromes).
    Count palindromes as we expand.
    */
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        
        for (int center = 0; center < 2 * n - 1; center++) {
            int left = center / 2;
            int right = left + (center % 2);
            
            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
        }
        
        return count;
    }
};
