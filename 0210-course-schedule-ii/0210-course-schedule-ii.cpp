class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        vector<int> courseOrder;

        // Build adjacency list and compute in-degrees
        for (const auto& prereq : prerequisites) {
            int course = prereq[0];
            int pre = prereq[1];
            adj[pre].push_back(course);
            inDegree[course]++;
        }

        // Initialize a queue with all courses having in-degree 0
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) 
                q.push(i);
        }

        // Process courses in topological order
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            courseOrder.push_back(curr);

            for (int next : adj[curr]) {
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