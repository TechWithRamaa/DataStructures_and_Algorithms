class Solution {
public:
    // Approach 1 
    // Kahns algorithm - Topological sorting
    // Dependency Graph -> A must be completed before B

    // graph has to be constructed using Dependency Graph Construction
    // inDegree vector has to be constructed -> no of prerequisites for a given node
    bool canFinish2(int numCourses, vector<vector<int>>& prerequisites) {
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

    // Approach 2 
    // DFS - Cycle detection
    // CRUX of this cycle detection 
    //0 (Unvisited)	- The node hasn't been visited yet - We can EXPLORE
    //1 (Visiting)	- The node is currently in the recursion stack (processing)
    //2 (Safe/Visited) - The node and all its dependencies have been processed, and it's in a safe path
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);

        for(auto& pre: prerequisites) {
            int a = pre[0], b = pre[1];
            graph[b].push_back(a);
        }

        vector<int> visited(numCourses, 0);
        for(int i = 0; i < numCourses; i++) {
            if(visited[i] == 0) {
                if(hasCycle(graph, visited, i) == true)
                    return false;
            }
        }

        return true;
    }

private:

    bool hasCycle(vector<vector<int>>& graph, vector<int>& visited, int node) {
        if(visited[node] == 1) 
            return true;

        if(visited[node] == 2) 
            return false;

        visited[node] = 1;
        for(auto neighbor : graph[node]) {
            if(hasCycle(graph, visited, neighbor) == true) {
                return true;
            }
        }

        visited[node] = 2;
        return false;
    }

};