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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
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