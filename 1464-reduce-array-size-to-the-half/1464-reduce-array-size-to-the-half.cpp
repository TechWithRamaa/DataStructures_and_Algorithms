class Solution {
public:
    // Frequence Map + MaxHeap + Greedy Simulation 
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freqMap;

        for(const auto& num : arr) {
            freqMap[num]++;
        }

        priority_queue<int> maxHeap;

        for(const auto& [num, freq] : freqMap) {
            maxHeap.push(freq);
        }

        int HALF_SIZE = arr.size() / 2;
        int removedNumbers = 0, totalNumbersRemoved = 0;
        while(totalNumbersRemoved < HALF_SIZE) {
            auto freq = maxHeap.top();
            maxHeap.pop();

            removedNumbers++;
            totalNumbersRemoved += freq;
        }

        return removedNumbers;
    }
};