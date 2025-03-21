class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        unordered_map<string, vector<string>> graph; // Adjacency list
        unordered_map<string, int> inDegree; // Tracks missing ingredients
        unordered_set<string> available(
            supplies.begin(),
            supplies.end()); // Fast lookup for available ingredients

        queue<string> q;       // Queue for BFS
        vector<string> result; // Stores the final recipes we can make

        // Step 1: Build the Graph & Compute inDegree
        for (int i = 0; i < recipes.size(); i++) {
            string recipe = recipes[i];
            inDegree[recipe] = 0; // Initialize recipe inDegree

            for (string& ingredient : ingredients[i]) {
                if (available.count(ingredient) ==
                    0) { // Only track missing dependencies
                    graph[ingredient].push_back(recipe);
                    inDegree[recipe]++;
                }
            }

            // If recipe has no missing dependencies, it can be made immediately
            if (inDegree[recipe] == 0) {
                q.push(recipe);
                result.push_back(recipe);
            }
        }

        // Step 2: Process Recipes in Order (Topological Sorting using BFS)
        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            // Make the current recipe available for other recipes
            available.insert(curr);

            // Process dependent recipes
            for (string& nextRecipe : graph[curr]) {
                inDegree[nextRecipe]--;

                if (inDegree[nextRecipe] == 0) { // Can now be made
                    q.push(nextRecipe);
                    result.push_back(nextRecipe);
                }
            }
        }

        return result;
    }
};