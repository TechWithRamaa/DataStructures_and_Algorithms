class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        vector<int> courseOrder;

        // Build adjacency list and compute in-degrees
        for (const auto& prereq : prerequisites) {
            int a = prereq[0], b = prereq[1];
            graph[b].push_back(a);
            inDegree[a]++;
        }

        // Initialize a queue with all courses having in-degree 0
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        // Process courses in topological order
        while (!q.empty()) {
            int currentCourse = q.front();
            q.pop();

            courseOrder.push_back(currentCourse);

            for (auto& next : graph[currentCourse]) {
                inDegree[next]--;
                if (inDegree[next] == 0)
                    q.push(next);
            }
        }

        // Check if topological sorting is valid (covers all courses)
        if (courseOrder.size() != numCourses)
            return {};

        return courseOrder;
    }
};