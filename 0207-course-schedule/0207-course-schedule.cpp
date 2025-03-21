class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);

        for(auto& pre : prerequisites) {
            int a = pre[0], b = pre[1];
            graph[b].push_back(a);
            inDegree[a]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }

        int coursesTaken = 0;
        while(!q.empty()) {
            int completedCourse = q.front();
            q.pop();

            for(auto dependent : graph[completedCourse]) {
                inDegree[dependent]--;
                if(inDegree[dependent] == 0) {
                    q.push(dependent);
                    // all its prerequisites are completed, now this dependent can be taken
                }
            }

            coursesTaken++;
        }

        return coursesTaken == numCourses;
    }
};