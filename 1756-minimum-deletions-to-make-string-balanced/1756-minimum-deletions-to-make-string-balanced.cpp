class Solution {
public:
    // A string is balanced if all 'a' characters appear before all 'b'
    // characters. The string becomes imbalanced at any point where you see a
    // 'b' followed later by an 'a'.

    /* Goal of the Problem

       We are allowed to delete characters so that, in the end:
       The string contains all 'a's first, followed by all 'b's.
       We want to do this with minimum deletions.
    */

    /*
    How do we make the optimal choice?

    When processing from left to right:

    If we see 'b' → it’s safe to keep it for now (it’s allowed before 'a').
    If we see 'a' after some 'b' → Now we have a conflict:

        Option 1: Remove this 'a' (cost +1).
        Option 2: Remove all previous 'b's (cost = b_count).
        We choose min(res+1, b_count).

    This is exactly what the greedy O(1) solution does.
    */
    int minimumDeletions(string s) {
        int b_count = 0, res = 0;
        
        for (char c : s) {
            if (c == 'b') {
                b_count++;
            } else { // 'a'
                res = min(res + 1, b_count);
            }
        }
        
        return res;
    }
};