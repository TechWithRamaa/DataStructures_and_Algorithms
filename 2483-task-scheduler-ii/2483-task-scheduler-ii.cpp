class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, long long> lastExecution;
        long long currentDay = 0;

        for(auto task : tasks) {
            currentDay += 1;

            if(lastExecution.contains(task)) {
                currentDay = max(currentDay, static_cast<long long>(lastExecution[task] + space + 1));
            } 

            lastExecution[task] = currentDay;
        }

        return currentDay;
    }
};