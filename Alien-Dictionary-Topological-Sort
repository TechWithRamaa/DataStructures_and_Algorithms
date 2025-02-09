class Solution {
public:
    string getTopoOrdering(vector<string>& words, string order) {
        unordered_map<char, unordered_set<char>> adjList;
        unordered_map<char, int> inDegree;

        for(auto& word : words) {
            for(auto character : word) {
                inDegree[character] = 0;
            }
        }

        for(int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i];
            string word2 = words[i+1];

            int minWordLength = min(word1.length(), word2.length());
            bool foundDifference = false;

            for(int j = 0; j < minWordLength; j++) {
                if(word1[j] != word2[j]) {
                   if(adjList[word1[j]].insert(word2[j]).second)
                        inDegree[word2[j]]++; 
                }
                foundDifference = true;
                break;
            }

            if(!foundDifference && word1.length() > word2.length())
                return ""; 
        }

        queue<char> q;
        for(auto &entry : inDegree) {
            if(entry.second == 0) 
                q.push(entry.first);
        }

        string result  = "";
        while(!q.empty()) {
            char nextChar = q.front();
            q.pop();

            result += nextChar;

            for(auto& entry : adjList[nextChar]) {
                if(--inDegree[entry] == 0)
                    q.push(entry);
            }
        }

        return result.size() == inDegree.size() ? result : "";
    }
};
