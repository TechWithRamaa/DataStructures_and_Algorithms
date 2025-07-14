class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> magazineFreq;
        unordered_map<char, int> ransomFreq;

        for(const auto& ch : magazine) {
            magazineFreq[ch]++;
        }

        for(const auto& ch : ransomNote) {
            ransomFreq[ch]++;
        }

        for(const auto& [ch, freq] : ransomFreq) {
            if(magazineFreq[ch] < freq) {
                return false;
            }
        }

        return true;
    }
};