class Solution {
    // Trie Node structure
    class TrieNode {
    public:
        TrieNode* children[2]; // For binary bits 0 and 1
        TrieNode() {
            children[0] = nullptr;
            children[1] = nullptr;
        }
    };

public:
    // Insert a number into the Trie
    void insert(TrieNode* root, int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) { // Process bits from MSB to LSB
            int bit = (num >> i) & 1;
            if (!node->children[bit]) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }

    // Query the Trie to find the maximum XOR for a given number
    int query(TrieNode* root, int num) {
        TrieNode* node = root;
        int maxXOR = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int toggledBit = 1 - bit; // Opposite bit
            if (node->children[toggledBit]) {
                maxXOR = (maxXOR << 1) | 1;
                node = node->children[toggledBit];
            } else {
                maxXOR = (maxXOR << 1);
                node = node->children[bit];
            }
        }
        return maxXOR;
    }

    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();

        // Insert all numbers into the Trie
        for (int num : nums) {
            insert(root, num);
        }

        // Find the maximum XOR for each number
        int maxResult = 0;
        for (int num : nums) {
            maxResult = max(maxResult, query(root, num));
        }

        return maxResult;
    }
};