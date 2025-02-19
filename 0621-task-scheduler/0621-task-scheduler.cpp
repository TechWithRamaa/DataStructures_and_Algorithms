class Solution {
public:
    // FrequenceMap + MaxHeap + Scheduling & Counting the intervals
    int leastInterval(vector<char>& tasks, int n) {
        int totalIntervals = 0;

        unordered_map<char, int> freqMap;
        for (auto task : tasks) {
            freqMap[task] += 1;
        }

        priority_queue<int> maxHeap; // Greedy logic of being taking the most
                                     // frequently occuring tasks
        for (auto [task, freq] : freqMap) {
            maxHeap.push(freq);
        }

        while (!maxHeap.empty()) {
            vector<int> waitList;
            int interval = 0;

            for (int i = 0; i < n + 1; i++) {
                if (!maxHeap.empty()) {
                    auto task = maxHeap.top();
                    maxHeap.pop();

                    interval += 1;

                    if (--task > 0) {
                        waitList.push_back(task);
                    }
                } else {
                    if (waitList.empty())
                        break;
                    interval += 1;
                }
            }

            for (auto task : waitList) {
                maxHeap.push(task);
            }

            totalIntervals += maxHeap.empty() ? interval : n + 1;
        }
        return totalIntervals;
    }
};