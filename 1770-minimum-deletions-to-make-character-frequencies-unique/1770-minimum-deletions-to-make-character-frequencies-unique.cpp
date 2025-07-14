class Solution {
public:
    // Greedy Frequency Deduplication
    int minDeletions(string s) {
        unordered_map<char, int> freqMap;
        
        for(const auto& ch : s) {
            freqMap[ch]++;
        }
        
        int deletions = 0;
        unordered_set<int> used;

        for(auto& [ch, freq] : freqMap) {
            while(freq > 0 && used.count(freq) > 0) {
                freq--;
                deletions++;
            }

            used.insert(freq);
        }

        return deletions;
    }
};