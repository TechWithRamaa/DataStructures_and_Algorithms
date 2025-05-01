class Solution {
public:
    // Binary Search on Answer + Greedy  
    // Very Interesting
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int maximumTasks = 0;

        int low = 0, high = min(tasks.size(), workers.size());
        while(low <= high) {
            int mid = low + ((high - low) / 2);

            bool feasibility = isFeasible(mid, tasks, workers, pills, strength);
            if(feasibility) {
                maximumTasks = mid; // store the best possible number of tasks
                low = mid + 1; // maximize the tasks 
            } else {
                high = mid - 1;
            }
        }

        return maximumTasks;
    }

private:
    bool isFeasible(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        multiset<int> workersStrength(workers.end() - k, workers.end());

        for(int i = k - 1; i >= 0; i--) {
            int requiredStrength = tasks[i];

            auto it = workersStrength.lower_bound(requiredStrength);
            if(it != workersStrength.end()) {
                workersStrength.erase(it);
            } else {
                int pillContributedStrength = requiredStrength - strength;
                it = workersStrength.lower_bound(pillContributedStrength);

                if(pills == 0 || it == workersStrength.end())
                   return false;
                
                pills--;
                workersStrength.erase(it);
            }
        }

        return true;
    }
};