class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int M = word1.length(), N = word2.length();
        
        string result = "";
        int i = 0, j = 0;
        while(i < M || j < N) {
            if(i < M) {
                result.push_back(word1[i++]); 
            }
            if(j < N) {
                result.push_back(word2[j++]);
            }
        }

        return result;
    }
};