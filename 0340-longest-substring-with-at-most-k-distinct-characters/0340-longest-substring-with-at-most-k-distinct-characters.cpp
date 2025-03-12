class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int longestSubString = 0;

        unordered_map<char, int> distinctCharMap;
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            distinctCharMap[s[right]]++;

            while (distinctCharMap.size() > k) {
                distinctCharMap[s[left]]--;
                if(distinctCharMap[s[left]] == 0) {
                    distinctCharMap.erase(s[left]);
                }
                left++;
            }

            longestSubString = max(longestSubString, right - left + 1);
        }

        return longestSubString;
    }
};