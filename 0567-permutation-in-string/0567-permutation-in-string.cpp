class Solution {
public:
    // the required tricks are
    // we always need to find a substring in s2 with matching lenght of s1
    // it naturally dissolves into fixed sliding window

    // permutation or anagram requires counting of characters
    // second necessity is we maintain a frequency map of both the strings
    // s2's frequencymap keeps getting updated as we slide the window

    // Check for frequency equality — not the exact string — since permutations allow any order.
    bool checkInclusion(string s1, string s2) {
        int N = s1.size();
        int M = s2.size();

        if (N > M) return false; 


        vector<int> freqS1Map(26, 0), freqS2Map(26, 0);

        for(auto c : s1) {
            freqS1Map[c - 'a']++;
        }

        // Fixed Sliding Window is already started here
        for(int i = 0; i < N; i++) {
            freqS2Map[s2[i] - 'a']++;
        }

        // Check initial window
        if (freqS1Map == freqS2Map) 
            return true;

        for(int i = N; i < M; i++) {
            freqS2Map[s2[i] - 'a']++;  // adding the frequency of newly entered character

            freqS2Map[s2[i - N] - 'a']--;  // subtracting the frequency of exiting character in the left

            if(freqS1Map == freqS2Map) {
                return true;
            }
        }

        return false;
    }
};