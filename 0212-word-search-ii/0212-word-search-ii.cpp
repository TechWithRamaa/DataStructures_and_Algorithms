struct TrieNode {
    TrieNode* children[26] = {nullptr};
    string wordEndsAs = ""; // Stores the full word if it ends here
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index])
                node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->wordEndsAs = word;
    }
};

class Solution {
private:
    void dfs(vector<vector<char>>& board, TrieNode* node,
             vector<string>& result, int i, int j, vector<vector<bool>>& visited) {
        
        int M = board.size(), N = board[0].size();
        char c = board[i][j];

        // Base conditions
        if (visited[i][j] || !node->children[c - 'a']) return;

        node = node->children[c - 'a'];

        if (!node->wordEndsAs.empty()) {
            result.push_back(node->wordEndsAs);
            node->wordEndsAs = ""; // Avoid duplicates
        }

        visited[i][j] = true;

        vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (auto [dr, dc] : directions) {
            int ni = i + dr, nj = j + dc;
            if (ni >= 0 && ni < M && nj >= 0 && nj < N)
                dfs(board, node, result, ni, nj, visited);
        }

        visited[i][j] = false; // Backtrack
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;

        // Step 1: Build Trie
        for (const string& word : words)
            trie.insert(word);

        int M = board.size(), N = board[0].size();
        vector<string> result;
        vector<vector<bool>> visited(M, vector<bool>(N, false));

        // Step 2: DFS from each cell
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                dfs(board, trie.root, result, i, j, visited);
            }
        }

        return result;
    }
};
