class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int totalIntervals = 0;
        
        unordered_map<char, int> freqMap;
        for(auto task : tasks) {
            freqMap[task] += 1;
        }

        priority_queue<int> maxHeap;
        for(auto [task, freq] : freqMap) {
            maxHeap.push(freq);
        }

        while(!maxHeap.empty()) {
            vector<int> waitList;
            int interval = 0;

            for(int i = 0; i < n + 1; i++) {
                if(!maxHeap.empty()) {
                    auto currentTask = maxHeap.top();
                    maxHeap.pop();

                    interval += 1;

                    if(--currentTask > 0) {
                        waitList.push_back(currentTask);
                    }
                } else {
                    if(waitList.empty())
                        break;

                    interval += 1;
                }
            }

            for(auto t : waitList) {
                maxHeap.push(t);
            }

            totalIntervals += maxHeap.empty() ? interval : n + 1;
        }

        return totalIntervals;
    }

    // This approach is based on mathematical greedy approach
    // Best suited for CP 
    // Quicker calculation, but works only on static set of tasks & interval
    // TC ~ O ( n log n ) ; SC ~ O (n)
    int leastIntervalMathGreedy(vector<char>& tasks, int n) {
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