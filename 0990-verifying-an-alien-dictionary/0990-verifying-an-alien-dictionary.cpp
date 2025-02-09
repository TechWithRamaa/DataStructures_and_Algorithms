class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> alienOrder;

        for(int i = 0; i < order.size(); i++) {
            alienOrder[order[i]] = i;
        }

        for(int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i];
            string word2 = words[i+1];

            int minWordLength = min(word1.length(), word2.length());
            bool foundDifference = false;

            for(int j = 0; j < minWordLength; j++) {
                if(word1[j] != word2[j]) {
                    if(alienOrder[word1[j]] > alienOrder[word2[j]])
                       return false;
                    foundDifference = true;
                    break;
                }
            }

            if(!foundDifference && word1.length() > word2.length())
                return false; 
        }

        return true;
    }
};