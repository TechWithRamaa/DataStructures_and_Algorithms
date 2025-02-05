class Solution {
public:
    bool isPalindrome(string s) {
        int leftIndex = 0;
        int rightIndex = s.length()-1;

        while(leftIndex < rightIndex) {
            while(leftIndex < rightIndex && !isalnum(s[leftIndex])) {
                leftIndex++;
            }

            while(leftIndex < rightIndex && !isalnum(s[rightIndex])) {
                rightIndex--;
            }

            if(tolower(s[leftIndex]) != tolower(s[rightIndex])) {
                return false;
            }

            leftIndex++;
            rightIndex--;
        }

        return true;
    }
};