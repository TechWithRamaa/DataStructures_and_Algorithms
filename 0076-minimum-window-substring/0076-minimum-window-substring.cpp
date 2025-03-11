class Solution {
public:
    // one of the unique problems I ve worked on
    // mistakes I committed 
    // counted freqMap for s instead of t (How silly)
    // not closed square brackets on map indices
    // if condition for checking new min was ulta

    // Dynamic Sliding Window
    // note down how frequency of each character is stored in 'targetMap'
    // and no of each character that occurred atleast once is stored in 'need'
    // these are very unique to this problem
    
    // if you closely observe, we used windowCount map to recall the characters we seen so far
    // as soon as a character enter the sliding window, we need to check the count required in the targetMap
    // if so, one need is satisifed
    // so we increment 'have'

    // if have meets needs
    // then we can calculate minLength
    // we shrink the window to find the best minLength as long as have == need is meeting 
    // whenever we update the minLength, we store the starting index of that minLenth substring
    // as soon as we decide to shrink the window, we have to decrement the leaving character in windowCount
    // when windowCount gets updated, regressively we update have

    // note down, we update minLength & have only when have == need
    string minWindow(string s, string t) {
        int minLengthWin = INT_MAX;
        int N = s.size();

        unordered_map<char, int> targetCount;
        for (auto c : t) {
            targetCount[c]++;
        }

        int left = 0, start = 0;
        int need = targetCount.size(), have = 0;
        unordered_map<char, int> windowCount;

        for (int right = 0; right < N; right++) {
            // step 1 - count the newly entered char into the window
            windowCount[s[right]]++; 

            if (targetCount.find(s[right]) != targetCount.end() &&
                targetCount[s[right]] == windowCount[s[right]]) {
                have++;
            }

            while (have == need) {
                if (minLengthWin > right - left + 1) {
                    minLengthWin = right - left + 1;
                    start = left; // noting down start index to extract substring
                }

                windowCount[s[left]]--;
                if (targetCount.find(s[left]) != targetCount.end() &&
                    targetCount[s[left]] > windowCount[s[left]]) {
                    have--;
                }

                left++;
            }
        }

        return minLengthWin == INT_MAX ? "" : s.substr(start, minLengthWin);
    }
};