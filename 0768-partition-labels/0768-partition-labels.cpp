class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> last; // Store last occurrence of each character
        vector<int> result;
        
        int n = s.size();

        // Step 1: Record the last index of each character
        // Pre-processing
        for (int i = 0; i < n; i++) {
            last[s[i]] = i;
        }

        // Step 2: Find partitions
        int maxEnd = 0, partitionStart = 0;
        for (int i = 0; i < n; i++) {
            maxEnd = max(maxEnd, last[s[i]]); // Expand partition range
            
            if (i == maxEnd) { // If we reach the furthest last occurrence, partition here
                result.push_back(i - partitionStart + 1);
                partitionStart = i + 1;
            }
        }

        return result;
    }
};
