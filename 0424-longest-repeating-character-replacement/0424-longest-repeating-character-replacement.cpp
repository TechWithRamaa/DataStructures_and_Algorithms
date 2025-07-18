class Solution {
public:
    // Dynamic Sliding Window
    int characterReplacement(string s, int k) {
        vector<int> frequency(26, 0);
        int mostFrequentCount = 0;
        int start = 0;
        int longestSubstring = 0;

        for(int end = 0; end < s.length(); end++) {
            frequency[s[end] - 'A']++;
            mostFrequentCount = max(mostFrequentCount, frequency[s[end] - 'A']);

            // Keep expanding the window until less frequent count breaches given k, 
            // then start shrinking

            // window_size - mostFrequentCount
            if(end - start + 1 - mostFrequentCount > k) {
                frequency[s[start] - 'A']--;
                start+=1;
            }

            longestSubstring = max(longestSubstring, end - start + 1);
        }

        return longestSubstring;
    }
};