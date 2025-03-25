class Solution {
public:
    // Fixed Sliding Window
    int maxVowels(string s, int k) {
        unordered_set vowelSet = {'a', 'e', 'i', 'o', 'u'};
        int maxCount = 0;
        int vowelsCount = 0;

        for(int i = 0; i < k; i++) {
            if(vowelSet.count(s[i])) {
                vowelsCount++;
            }
        }

        maxCount = vowelsCount;

        for(int end = k; end < s.length(); end++) {
            // Outgoing element
            if(vowelSet.count(s[end - k])) {
                vowelsCount--;
            }

            // Incoming eleement
            if(vowelSet.count(s[end])) {
                vowelsCount++;
            }

            maxCount = max(maxCount, vowelsCount);
        }

        return maxCount;
    }
};