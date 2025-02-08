class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegrees(numCourses, 0);

        for(auto& entry: prerequisites) {
            int preReq = entry[1];
            int course = entry[0];
            adjList[preReq].push_back(course);
            inDegrees[course] += 1;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(inDegrees[i] == 0) {
                q.push(i);
            }
        }

        int courses = 0;
        while(!q.empty()) {
            int currentCourse = q.front();
            q.pop();

            courses += 1;
            for(auto next : adjList[currentCourse]) {
                if(--inDegrees[next] == 0) {
                    q.push(next);
                }
            }
        }

        return courses == numCourses;
    }
};