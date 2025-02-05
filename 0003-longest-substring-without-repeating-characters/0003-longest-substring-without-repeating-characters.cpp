class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastIndicesMap;

        int start = 0;
        int maxLength = 0;

        for(int end = 0; end < s.length(); end++) {
            char currentChar = s[end];

            if(lastIndicesMap.find(currentChar) != lastIndicesMap.end() && lastIndicesMap[currentChar] >= start) {
                start = lastIndicesMap[currentChar] + 1;
            } 

            lastIndicesMap[currentChar] = end;
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};