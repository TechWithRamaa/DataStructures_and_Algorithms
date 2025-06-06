class Solution {
public:
    /*
    int lengthOfLongestSubstring(string s) {
        vector<int> counter(256, 0) ; // stores the last index of every character encountered

        int start = 0;
        int maxLength = 0;

        for(int end = 0; end < s.length(); end++) {
            char currentChar = s[end];

            while(counter[currentChar] >= 1) {
                counter[s[start]] -= 1;
                start += 1;
            } 

            counter[currentChar] += 1;
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }*/

    /*
    // HashMap approach aids in quicker shrinking of windows
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastIndicesMap; // stores the last index of every character encountered

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
     */
    
    // Dynamic Sliding Window
    // Set approach - Shrinks the window by 1 unit
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int left = 0;
        int maxSubStringLength = 0;
        
        for(int right = 0; right < s.length(); right++) {
            while(window.count(s[right])) {
                window.erase(s[left]);
                left++;
            } 
            window.insert(s[right]);
            maxSubStringLength = max(maxSubStringLength, right - left + 1);
        }
        
        return maxSubStringLength;
    }


};