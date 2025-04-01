struct TrieNode {
    TrieNode* children[26] = {nullptr};
    string wordEndsAs = "";
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;

        for(auto c : word) {
            if(!node->children[c - 'a'])
                node->children[c - 'a'] = new TrieNode();
            
            node = node->children[c - 'a'];
        }

        node->wordEndsAs = word;
    }
};

class Solution {
private: 
    void dfs(vector<vector<char>>& board, TrieNode* node, vector<string>& result, int i, int j, vector<vector<bool>>& visited) {
        
        if(visited[i][j] == true)
            return;

        auto c = board[i][j];
        
        if(!node->children[c - 'a'])
            return;
        
        node = node->children[c - 'a'];
        if(!node->wordEndsAs.empty()) {
            result.push_back(node->wordEndsAs);
            node->wordEndsAs = "";
        }
        
        visited[i][j] = true;

        vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int M = board.size(), N = board[0].size();

        for(auto [dr, dc] : directions) {
            int nr = i + dr;
            int nc = j + dc;

            if(nr >= 0 && nr < M && nc >= 0 && nc < N) {
                dfs(board, node, result, nr, nc, visited);
            }
        }

        visited[i][j] = false;

        bool isLeaf = true;
        for(TrieNode* child : node->children) {
            if(!child) {
                isLeaf = false;
                break;
            }      
        }

        if(isLeaf) 
            node = nullptr;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;

        for(auto word : words) 
            trie.insert(word);
        
        int M = board.size(), N = board[0].size();
        vector<string> result;
        vector<vector<bool>> visited(M, vector<bool>(N, false));

        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                dfs(board, trie.root, result, i, j, visited);
            }
        }

        return result;
    }
};

