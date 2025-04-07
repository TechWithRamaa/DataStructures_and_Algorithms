class Solution {
public:
    // BFS - String Search State
    // Calculating Neighbors is the key aspect of this problem
    // which is done brilliantly
    int minMutation(string startGene, string endGene, vector<string>& bank) {

        unordered_set<string> validState(bank.begin(), bank.end());
        if (!validState.count(endGene))
            return -1;

        vector<char> choices = {'A', 'C', 'G', 'T'};

        unordered_set<string> visited;
        queue<pair<string, int>> q;
        q.emplace(startGene, 0);
        visited.insert(startGene);

        while (!q.empty()) {
            auto [current, steps] = q.front();
            q.pop();

            if (current == endGene)
                return steps;

            for (int i = 0; i < current.size(); i++) {
                
                char originalChar = current[i];
                for (char c : choices) {
                    if(originalChar == c)
                        continue;

                    current[i] = c;
                    if(validState.count(current) > 0 && !visited.count(current)) {
                        q.emplace(current, steps + 1);
                        visited.insert(current);
                    }
                    current[i] = originalChar;
                }
            }
        }

        return -1;
    }
};