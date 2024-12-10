class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       // Step 1: Count the frequency of each task
        unordered_map<char, int> freqMap;
        for (char task : tasks) {
            freqMap[task]++;
        }

        // Step 2: Store frequencies in a vector and sort in descending order
        vector<int> frequencies;
        for (auto& pair : freqMap) {
            frequencies.push_back(pair.second);
        }
        sort(frequencies.rbegin(), frequencies.rend());

        // Step 3: Determine the maximum frequency
        int maxFreq = frequencies[0];
        int idleSlots = (maxFreq - 1) * n;

        // Step 4: Fill idle slots with tasks
        for (int i = 1; i < frequencies.size(); i++) {
            idleSlots -= min(frequencies[i], maxFreq - 1);
        }

        // Step 5: Calculate the total intervals
        idleSlots = max(0, idleSlots);
        return tasks.size() + idleSlots;  
    }
};