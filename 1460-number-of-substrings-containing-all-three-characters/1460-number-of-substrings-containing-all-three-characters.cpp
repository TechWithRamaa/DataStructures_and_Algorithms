class Solution {
public:
    // Window Sliding - Dynamic
    // Counting trick is used to calculate no of valid substrings
    // avoided redudant counting & used brilliantly

    // Many problems hide simple counting formulas in what initially appears to
    // be a difficult problem Instead of iterating over every possible ending
    // index r' > r, we realize that all substrings starting at l and ending at
    // r' ≥ r are automatically valid.
    int numberOfSubstrings(string s) {
        int count = 0;

        int freqArray[26] = {0};
        int N = s.size();
        int left = 0;

        for (int right = 0; right < N; right++) {
            freqArray[s[right] - 'a']++;

            while (freqArray['a' - 'a'] && freqArray['b' - 'a'] &&
                   freqArray['c' - 'a']) {
                count += N - right; // look here for counting logic
                freqArray[s[left] - 'a']--;
                left++;
            }
        }

        return count;
    }
};