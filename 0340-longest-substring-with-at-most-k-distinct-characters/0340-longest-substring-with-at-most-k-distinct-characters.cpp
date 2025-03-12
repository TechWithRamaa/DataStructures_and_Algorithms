class Solution {
public:
    // Dynamic Sliding Window
    // Mistakes I made while solving myself

    // I used an unordered_set to track distinct characters
    // The set cannot handle cases where multiple instances of the
    // same character are allowed within the valid window.

    // Use an unordered_map to track character frequencies instead.

    // I forgot to 
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int longestSubString = 0;

        unordered_map<char, int> distinctCharMap;
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            distinctCharMap[s[right]]++;

            while (distinctCharMap.size() > k) {
                distinctCharMap[s[left]]--;
                
                if(distinctCharMap[s[left]] == 0) {
                    // I forgot this erase 
                    // Very silly !!! 
                    // Consequences were very bad
                    distinctCharMap.erase(s[left]);
                } 
                
                left++;
            }

            longestSubString = max(longestSubString, right - left + 1);
        }

        return longestSubString;
    }
};