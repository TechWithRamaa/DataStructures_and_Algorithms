class Solution {
public:
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