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

    int getParent(int x) {
        if(parent[x] != x) 
            parent[x] = getParent(parent[x]);
        
        return parent[x];
    }

    void unionOfXAndY(int x, int y) {
        int rootX = parent[x];
        int rootY = parent[y];

        if(rootX != rootY) {
            if(rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rootX < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootX] = rootY;
                rank[rootY]++;
            }
        }
    }

};

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

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DSU dsu;
        unordered_map<string, string> emailToName;
        unordered_map<string, unordered_set<string>> unions;

        // Step 1: Union emails and map each email to the corresponding name
        for (const auto& account : accounts) {
            const string& name = account[0];
            for (size_t i = 1; i < account.size(); ++i) {
                emailToName[account[i]] = name;
                dsu.unite(account[1], account[i]);
            }
        }

        // Step 2: Group emails by their root parent
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

class Solution1 {
public:
    // 1 => Graph Construction with AdjacencyList along with mapping of email
    // with their account owner 2 => DFS for component exploration on the email
    // for every distinct exploration 3 => Sorting as expected in the result

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