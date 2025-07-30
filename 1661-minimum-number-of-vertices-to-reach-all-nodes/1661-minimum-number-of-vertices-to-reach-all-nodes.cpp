class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> hasIncoming(n, false);

        // Mark nodes that have incoming edges
        for (auto& edge : edges) {
            hasIncoming[edge[1]] = true;
        }

        vector<int> result;

        // Nodes with no incoming edges must be in the result
        for (int i = 0; i < n; ++i) {
            if (!hasIncoming[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};


/*
If you want to reach all nodes:

You must start from the nodes that cannot be reached from anywhere else.
Those are the nodes with 0 in-degree.

*/