class TrieNode {
public:
    bool isEnd; 
    vector<TrieNode*> children;

    TrieNode() : isEnd(false), children(26, nullptr) {}
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode(); 
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a'; 
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode(); 
            }
            node = node->children[index];
        }
        node->isEnd = true; 
    }

    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                return false; 
            }
            node = node->children[index];
        }
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                return false; 
            }
            node = node->children[index];
        }
        return true; 
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */