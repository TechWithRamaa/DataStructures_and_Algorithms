class Solution {
public:
    bool isPalindromeX(int x) {
        string s = to_string(x);
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }

    bool isPalindrome(int x) {
        // Edge case: negative numbers or those ending in 0 (but not 0 itself)
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // For even/odd digits, compare accordingly
        return x == reversedHalf || x == reversedHalf / 10;
    }
};