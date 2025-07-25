class Solution {
public:
    /*
        Term	    Meaning
        Strictly    increasing but only unique allowed	a₁ < a₂ < a₃ < ...
        Monotone    increasing but duplicates allowed	a₁ ≤ a₂ ≤ a₃ ≤ ...
    */

    // Monotone increasing binary string = all 0s followed by all 1s
    int minFlipsMonoIncr(string s) {
        int N = s.length();
        vector<int> prefixOnes(N + 1, 0);

        for(int i = 0; i < N; i++) {
            prefixOnes[i + 1] = prefixOnes[i] + (s[i] == '1' ? 1 : 0);
        }

        int minFlips = INT_MAX;

        for(int i = 0; i <= N; i++) {
            int onesToFlip =  prefixOnes[i];
            int zerosToFlip = (N - i) - (prefixOnes[N] - prefixOnes[i]);

            minFlips = min(minFlips, onesToFlip + zerosToFlip);
        }

        return minFlips;
    }
};