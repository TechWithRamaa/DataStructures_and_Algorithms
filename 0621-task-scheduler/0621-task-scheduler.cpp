class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freqMap;
        for (char task : tasks) 
            freqMap[task]++;

        vector<int> frequencies;
        for (auto& pair : freqMap) 
            frequencies.push_back(pair.second);
        
        sort(frequencies.rbegin(), frequencies.rend());

        int maxFreq = frequencies[0];
        int idleSlots = (maxFreq - 1) * n;

        for (int i = 1; i < frequencies.size(); i++) 
            idleSlots -= min(frequencies[i], maxFreq - 1);
        
        idleSlots = max(0, idleSlots);
        return tasks.size() + idleSlots;  
    }
};