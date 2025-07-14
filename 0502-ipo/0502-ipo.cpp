class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int N = profits.size();

        // pair format for easy access
        vector<pair<int,int>> projects;
        for(int i = 0; i < N; i++) {
            projects.push_back({capital[i], profits[i]});
        }

        // sorting based on capital in ascending order
        sort(projects.begin(), projects.end());
        
        priority_queue<int> maxHeap; // maxHeap for projects yielding maximum project
        int index = 0;
        
        for(int i = 1; i <= k; i++) {
            while(index < N && projects[index].first <= w) {
                maxHeap.push(projects[index].second);
                index++;
            }

            if(!maxHeap.empty()) {
                w += maxHeap.top();
                maxHeap.pop();
            }
        }

        return w;
    }
};