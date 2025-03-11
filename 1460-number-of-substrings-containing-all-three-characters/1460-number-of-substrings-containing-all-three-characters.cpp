class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;

        int freqArray[26] = {0};
        int N = s.size();
        int left = 0;

        for(int right = 0; right < N; right++) {
            freqArray[s[right] - 'a']++;

            while(freqArray['a' - 'a'] 
                && freqArray['b' - 'a'] && freqArray['c' - 'a']) {
                    count += N - right;
                    freqArray[s[left] - 'a']--;
                    left++;
            }
        }


        return count;
    }
};