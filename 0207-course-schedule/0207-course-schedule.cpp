class Solution {
public:
    // Approach 1 
    // Kahns algorithm - Topological sorting
    // Dependency Graph -> A must be completed before B
    
    // graph has to be constructed using Dependency Graph Construction
    // inDegree vector has to be constructed -> no of prerequisites for a given node
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