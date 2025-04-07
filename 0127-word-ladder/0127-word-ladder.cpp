class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> givenWords(wordList.begin(), wordList.end());
        if(givenWords.count(endWord) < 0) return 0; 
        
        queue<pair<string, int>> levels;
        levels.push({beginWord, 1});

        while(!levels.empty()) {
            auto [currentWord, steps] = levels.front();
            levels.pop();

            if(currentWord == endWord) 
                return steps;
            
            for(int i = 0; i < currentWord.length(); i++) {
                char originalChar = currentWord[i];
                for(char c = 'a'; c <= 'z'; c++) {
                    currentWord[i] = c;
                    if(givenWords.count(currentWord) > 0) {
                        levels.push({currentWord, steps + 1});
                        givenWords.erase(currentWord);
                    }
                }
                currentWord[i] = originalChar;
            }
        }

        return 0;
    }
};