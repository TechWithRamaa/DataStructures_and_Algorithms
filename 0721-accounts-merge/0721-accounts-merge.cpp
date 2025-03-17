class UnionFind {
public:
    vector<int> parent;

    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int x) {
        if (parent[x] != x)
            parent[x] = findParent(parent[x]); // Path compression

        return parent[x];
    }

    void unionDisjoint(int x, int y) {
        int rootX = findParent(x);
        int rootY = findParent(y);
        if (rootX != rootY)
            parent[rootY] = rootX;
    }
};

class Solution {
public:
    // 1 => Graph Construction with AdjacencyList along with mapping of email with their account owner
    // 2 => DFS for component exploration on the email for every distinct exploration
    // 3 => Sorting as expected in the result

    // 1 => TC ~ O ( m )
    // 2 => TC ~ O ( m )
    // 3 => TC ~ O ( m log m )
    // final => TC ~ O ( m + m + m log m ) => O ( m log m )
    // final => TC ~ O ( m + m + m ... ) => O ( m )
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, string> emailToAccount;

        // graph & emailToAccount is constructed
        for(const auto& accountDetails : accounts) {
            string name = accountDetails[0];

            for(int i = 1; i < accountDetails.size(); i++) {
                emailToAccount[accountDetails[i]] = name;
                
                if(i == 1) // avoiding self loop
                    continue;
                
                graph[accountDetails[1]].push_back(accountDetails[i]);
                graph[accountDetails[i]].push_back(accountDetails[1]);
            }
        }

        vector<vector<string>> result;

        unordered_set<string> visitedSet;
        for(auto [email, accountName] : emailToAccount) {
            if(!visitedSet.count(email)) {
                
                vector<string> component;
                dfs(email, component, visitedSet, graph);

                sort(component.begin(), component.end());

                component.insert(component.begin(), accountName);
                result.push_back(component);
            }
        }

        return result;
    }

    private: 
        void dfs(string email, vector<string>& component, 
                    unordered_set<string>& visited, unordered_map<string, vector<string>>& graph) {
            visited.insert(email);
            component.push_back(email);

            for(auto& neighbor : graph[email]) {
                if(!visited.count(neighbor)) {
                    dfs(neighbor, component, visited, graph);
                }
            }

        }

    vector<vector<string>> accountsMerge1(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailToIndex;
        unordered_map<string, string> emailToName;
        int n = accounts.size();

        UnionFind uf(n);

        // Step 1: Map emails to accounts and perform unions
        for (int i = 0; i < n; i++) {
            string name = accounts[i][0];
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                emailToName[email] = name;
                if (emailToIndex.find(email) == emailToIndex.end())
                    emailToIndex[email] = i;
                else
                    uf.unionDisjoint(i, emailToIndex[email]);
            }
        }

        // Step 2: Group emails by their root account
        unordered_map<int, vector<string>> groupedEmails;
        for (const auto& [email, _] : emailToIndex) {
            int root = uf.findParent(emailToIndex[email]);
            groupedEmails[root].push_back(email);
        }

        // Step 3: Construct the result
        vector<vector<string>> result;
        for (auto& [root, emails] : groupedEmails) {
            sort(emails.begin(), emails.end());
            vector<string> account;
            account.push_back(emailToName[emails[0]]); // Add the name
            account.insert(account.end(), emails.begin(), emails.end());
            result.push_back(account);
        }

        return result;
    }
};