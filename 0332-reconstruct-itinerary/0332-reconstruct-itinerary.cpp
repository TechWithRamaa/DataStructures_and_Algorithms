#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <stack>
#include <deque>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> adj;
        
        // Build the graph
        for (auto& ticket : tickets) {
            adj[ticket[0]].insert(ticket[1]);
        }
        
        vector<string> result;
        stack<string> stk;
        stk.push("JFK");  // Always start from "JFK"

        while (!stk.empty()) {
            string node = stk.top();
            
            // If there are destinations left, visit the lexicographically smallest
            if (!adj[node].empty()) {
                string next = *adj[node].begin();  // Get the smallest destination
                adj[node].erase(adj[node].begin()); // Remove it from the multiset
                stk.push(next);
            } else {
                // If no outgoing edges, add to result and backtrack
                result.push_back(node);
                stk.pop();
            }
        }
        
        // Reverse the result as we built it in postorder
        reverse(result.begin(), result.end());
        return result;
    }
};
