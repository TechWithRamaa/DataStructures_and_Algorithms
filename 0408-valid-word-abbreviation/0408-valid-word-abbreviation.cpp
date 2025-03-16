class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int W = word.length();
        int A = abbr.length();

        int i = 0, j = 0;
        while (i < W && j < A) {
            if (isdigit(abbr[j])) {
                if (abbr[j] == '0') {
                    return false;
                }

                int num = 0;
                while (j < A && isdigit(abbr[j])) {
                    num = num * 10 + (abbr[j] - '0');
                    j++;
                }

                i += num;
            } else {
                if (abbr[j] != word[i])
                    return false;

                i++;
                j++;
            }
            
        }

        return i == W && j == A;
    }
};