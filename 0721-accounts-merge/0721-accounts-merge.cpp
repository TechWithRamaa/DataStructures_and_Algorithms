// Traditional Implementation of DSU
class UnionDisjointSet {
private:
    vector<int> parent, rank;

public:
    UnionDisjointSet(int N) {
        parent.resize(N);
        rank.resize(N, 0);

        for(int i = 0; i < N; i++) 
            parent[i] = i;
    }

    int getRoot(int x) {
        if(parent[x] != x) 
            parent[x] = getRoot(parent[x]);
        
        return parent[x];
    }

    void unionOfXAndY(int x, int y) {
        int rootX = getRoot(x);
        int rootY = getRoot(y);

        if(rootX != rootY) {
            if(rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootX] = rootY;
                rank[rootY]++;
            }
        }
    }

};

// My go-to approach
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailToAccountIndexMap;
        UnionDisjointSet disjointSet(accounts.size());

        for(int i = 0; i < accounts.size(); i++) {
            string accountName = accounts[i][0];

            for(int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if(emailToAccountIndexMap.find(email) == emailToAccountIndexMap.end()) {
                    emailToAccountIndexMap[email] = i;
                } else {
                    // merging of 2 accounts having atleast 1 common email 
                    disjointSet.unionOfXAndY(emailToAccountIndexMap[email], i); 
                }
            }
        }

        unordered_map<int, vector<string>> groupingEmailByRootParent;
        for(auto [email, accountIndex] : emailToAccountIndexMap) {
            int rootParent = disjointSet.getRoot(accountIndex);
            groupingEmailByRootParent[rootParent].push_back(email);
        }

        vector<vector<string>> result;
        for(auto [rootParent, emails] : groupingEmailByRootParent) {
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), accounts[rootParent][0]);
            result.push_back(emails);
        }

        return result;
    }
        
};

// Contextual Implementation of DSU according to the problem's nature
class DSU {
public:
    DSU() {}

    // Find the root of the node with path compression
    string find(const string& x) {
        if (parent.find(x) == parent.end())
            parent[x] = x;
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Union two nodes
    void unite(const string& x, const string& y) {
        string rootX = find(x);
        string rootY = find(y);
        if (rootX != rootY)
            parent[rootY] = rootX;
    }

private:
    unordered_map<string, string> parent;
};

class Solution3 {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DSU dsu;
        unordered_map<string, string> emailToName;
      
        // Step 1: Union emails and map each email to the corresponding name
        for (const auto& account : accounts) {
            const string& name = account[0];
            for (size_t i = 1; i < account.size(); ++i) {
                emailToName[account[i]] = name;
                dsu.unite(account[1], account[i]);
            }
        }

        // Step 2: Group emails by their root parent
        unordered_map<string, unordered_set<string>> unions;
        for (const auto& [email, _] : emailToName) {
            unions[dsu.find(email)].insert(email);
        }

        // Step 3: Prepare the result
        vector<vector<string>> result;
        for (const auto& [_, group] : unions) {
            vector<string> emails(group.begin(), group.end());
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), emailToName[*group.begin()]);
            result.push_back(emails);
        }

        return result;
    }
};

// Graph Construction + DFS approach
class Solution1 {
public:
    // 1 => Graph Construction with AdjacencyList along with mapping of email
    // with their account owner
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
        for (const auto& accountDetails : accounts) {
            string name = accountDetails[0];

            for (int i = 1; i < accountDetails.size(); i++) {
                emailToAccount[accountDetails[i]] = name;

                if (i == 1) // avoiding self loop
                    continue;

                graph[accountDetails[1]].push_back(accountDetails[i]);
                graph[accountDetails[i]].push_back(accountDetails[1]);
            }
        }

        vector<vector<string>> result;

        unordered_set<string> visitedSet;
        for (auto [email, accountName] : emailToAccount) {
            if (!visitedSet.count(email)) {

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
             unordered_set<string>& visited,
             unordered_map<string, vector<string>>& graph) {
        visited.insert(email);
        component.push_back(email);

        for (auto& neighbor : graph[email]) {
            if (!visited.count(neighbor)) {
                dfs(neighbor, component, visited, graph);
            }
        }
    }
};