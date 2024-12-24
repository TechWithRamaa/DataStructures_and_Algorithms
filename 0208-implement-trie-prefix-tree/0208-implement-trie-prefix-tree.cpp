class TrieNode {
public:
    bool isEnd; // Marks the end of a word
    vector<TrieNode*> children; // Pointers to child nodes

    TrieNode() : isEnd(false), children(26, nullptr) {} // Initialize with 26 null pointers for each alphabet letter
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode(); // Create root node
    }
    
     // Insert a word into the Trie
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a'; // Map character to index (0-25)
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode(); // Create a new node if it doesn't exist
            }
            node = node->children[index];
        }
        node->isEnd = true; // Mark the end of the word
    }

    // Search for a word in the Trie
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                return false; // Word not found
            }
            node = node->children[index];
        }
        return node->isEnd; // Check if it's marked as a complete word
    }

    // Check if any word starts with the given prefix
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                return false; // Prefix not found
            }
            node = node->children[index];
        }
        return true; // Prefix exists
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */