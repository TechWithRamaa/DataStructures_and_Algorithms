class Solution {
public:
    bool validPalindrome(string s) {
        int N = s.length();
        int left = 0, right = N - 1;

        while(left < right) {
            if(s[left] != s[right])
                return isValidPalindrome(s, left + 1, right) || isValidPalindrome(s, left, right - 1);

            left++;
            right--;
        }

        return true;
    }

    bool isValidPalindrome(const string& s, int left, int right) {
        while(left < right) {
            if(s[left] != s[right])
                return false;
                
            left++;
            right--;
        }

        return true;
    }
};