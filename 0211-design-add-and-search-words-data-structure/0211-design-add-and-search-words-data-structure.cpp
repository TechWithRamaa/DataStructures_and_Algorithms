class WordDictionary {
private:
    struct TrieNode {
        TrieNode* children[26] = {};
        bool isEnd = false;
    };

    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        
        for (char c : word) {
            int index = c - 'a';
            
            if (node->children[index] == nullptr)
                node->children[index] = new TrieNode();
            
            node = node->children[index];
        }
        
        node->isEnd = true;
    }

    bool search(string word) {
        return searchFrom(word, 0, root);
    }

    bool searchFrom(const string& word, int pos, TrieNode* node) {
        for (int i = pos; i < word.length(); i++) {
            char c = word[i];
            if (c == '.') {
                // Try all children from this point
                for (int j = 0; j < 26; j++) {
                    if (node->children[j] && searchFrom(word, i + 1, node->children[j])) {
                        return true;
                    }
                }
                return false; // No path worked
            } else {
                int index = c - 'a';
                
                if (node->children[index] == nullptr)
                    return false;
                
                node = node->children[index];
            }
        }

        return node && node->isEnd;
    }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */