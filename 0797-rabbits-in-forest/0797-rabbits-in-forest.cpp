class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> freqMap;
        for (int ans : answers)
            freqMap[ans]++;

        int res = 0;
        for (auto& [x, freq] : freqMap) {
            int groupSize = x + 1;
            int groupCount = (freq + x) / groupSize; // ceil(freq / groupSize)
            res += groupCount * groupSize;
        }
        return res;
    }
};