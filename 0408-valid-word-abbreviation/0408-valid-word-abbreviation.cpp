class Solution {
public:
    // 2 pointer approach
    // TC ~ O ( n )
    // always categorize into 2 types
    // is it a digit or a alphabet
    // logic becomes simple 
    
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