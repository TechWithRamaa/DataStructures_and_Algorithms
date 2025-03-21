class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        unordered_map<string, int> inDegree;
        unordered_map<string, vector<string>> graph;
        unordered_set<string> available(supplies.begin(), supplies.end());

        for (int i = 0; i < recipes.size(); i++) {
            string recipe = recipes[i];
            inDegree[recipe] = 0;
            for (auto ingredient : ingredients[i]) {
                if (available.count(ingredient) == 0) {
                    graph[ingredient].push_back(recipe);
                    inDegree[recipe]++;
                }
            }
        }

        queue<string> q;
        for(auto [key, value] : inDegree) {
            if(value == 0) {
                q.push(key);
            }
        }

        vector<string> result;

        while(!q.empty()) {
            auto processing = q.front();
            q.pop();

            result.push_back(processing);

            for(auto dependent : graph[processing]) {
                inDegree[dependent]--;

                if(inDegree[dependent] == 0) {
                    q.push(dependent);
                }
            }
        }

        return result;
    }
};