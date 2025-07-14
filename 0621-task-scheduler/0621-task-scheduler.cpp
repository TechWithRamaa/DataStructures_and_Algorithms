class Solution {
public:
    // counting frequency + maxHeap + scheduling simulation + greedy
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freqMap;

        for(const auto& ch : tasks) {
            freqMap[ch]++;
        }

        // maxHeap to store the most frequent tasks at the top
        priority_queue<int> maxHeap;
        for(const auto& [key, entry] : freqMap) {
            maxHeap.push(entry);
        }

        int totalTime = 0;

        while(!maxHeap.empty()) {
            vector<int> waitList;
            int interval = 0;

            for(int i = 0; i < n + 1; i++) {
                if(!maxHeap.empty()) {
                    auto task = maxHeap.top();
                    maxHeap.pop();

                    interval++; // real-clock

                    // if a task still has frequency to execute, push into waitList to be 
                    // executed after N clocks/interval
                    if(--task > 0) { 
                        waitList.push_back(task);
                    }
                } else {
                    if(waitList.empty())
                        break; // break when no tasks in maxHeap as well as in waitList
                    
                    interval++; // stay idle as there no tasks in MaxHeap
                }
            }

            for(auto task : waitList) {
                maxHeap.push(task);
            }

            totalTime += maxHeap.empty() ? interval : n + 1;
        }

        return totalTime;
    }
};