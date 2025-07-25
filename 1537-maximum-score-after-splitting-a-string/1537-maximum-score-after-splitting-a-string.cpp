class Solution {
public:
    /*
    We use prefix-suffix in splitting problems because:
        We're analyzing two parts of a structure.
        We want to avoid repeated computation.
        We can compute one part on the fly (prefix), and derive the other (suffix) from totals.
    */
    int maxScore(string s) {
        int totalOnes = count(s.begin(), s.end(), '1');

        int leftZeros = 0, rightOnes = totalOnes;
        int maxScore = 0;

        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == '0')
                leftZeros++;
            else
                rightOnes--;
                
            maxScore = max(maxScore, leftZeros + rightOnes);
        }

        return maxScore;
    }
};