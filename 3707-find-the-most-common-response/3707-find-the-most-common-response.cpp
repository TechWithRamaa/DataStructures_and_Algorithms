class Solution {
public:
    /*
    Revision tips 
        For each day:
            - Build set of responses (deduplication).
            - Directly count words from set.

        At end:
            - Find max frequency word (breaking ties lex order).
    */
    string findCommonResponse(vector<vector<string>>& responses) {
        string result;

        unordered_map<string, int> freq;
        for(auto &dayResponse : responses) {
            unordered_set<string> s(dayResponse.begin(), dayResponse.end());
        
            for(auto &w : s) {
                freq[w]++;
            }
        }

        int maxCount = 0;
        for(auto &[word, count] : freq) {
            if(count > maxCount || (count == maxCount && word < result)) {
                maxCount = count;
                result = word;
            }
        }

        return result;
    }
};