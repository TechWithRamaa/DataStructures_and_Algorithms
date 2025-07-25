class Solution {
public:
    /*
        Term	    Meaning
        Strictly    increasing but only unique allowed	a₁ < a₂ < a₃ < ...
        Monotone    increasing but duplicates allowed	a₁ ≤ a₂ ≤ a₃ ≤ ...
    */

    // Monotone increasing binary string = all 0s followed by all 1s

    /*
        Monotone increasing → 000...0111...1 structure.
        Try all split points where left is 0s, right is 1s.
        Use prefix sums to count 1s on left, 0s on right efficiently.
        Take minimum of all options.
    */
    int minFlipsMonoIncr(string s) {
        int N = s.length();
        vector<int> prefixOnes(N + 1, 0);

        for(int i = 0; i < N; i++) {
            prefixOnes[i + 1] = prefixOnes[i] + (s[i] == '1' ? 1 : 0);
        }

        int minFlips = INT_MAX;

        for(int i = 0; i <= N; i++) {
            int onesToFlip =  prefixOnes[i]; // no of ones in the left part
            int zerosToFlip = (N - i) - (prefixOnes[N] - prefixOnes[i]); // no of zero in the right part

            minFlips = min(minFlips, onesToFlip + zerosToFlip);
        }

        return minFlips;
    }
};