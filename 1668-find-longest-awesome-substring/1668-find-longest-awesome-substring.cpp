class Solution {
public:
    int longestAwesome(string s) {
        unordered_map<int, int> firstOccurrence;
        firstOccurrence[0] = -1;
        int maxLength = 0;
        int mask = 0;

        for (int i = 0; i < s.size(); i++) {
            // Toggle the bit corresponding to the current digit
            int digit = s[i] - '0';
            mask ^= (1 << digit);

            // Check if this exact bitmask has been seen before
            if (firstOccurrence.count(mask)) 
                maxLength = max(maxLength, i - firstOccurrence[mask]);
             else 
                firstOccurrence[mask] = i;
            
            // Check all single-bit flips of the current bitmask
            for (int j = 0; j < 10; ++j) {
                int flippedMask = mask ^ (1 << j);
                if (firstOccurrence.count(flippedMask)) 
                    maxLength = max(maxLength, i - firstOccurrence[flippedMask]);
            }
        }

        return maxLength;
    }
};