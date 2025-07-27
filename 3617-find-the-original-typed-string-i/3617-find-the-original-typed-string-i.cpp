class Solution {
public:
     int possibleStringCount(string word) {
        int n = word.size(), ans = 1;
        for (int i = 1; i < n; ++i) {
            if (word[i - 1] == word[i]) {
                ++ans;
            }
        }
        return ans;
    }
    
    // Actual Generation is not necessary
    int possibleStringCountD(string word) {
        int N = word.size();
        vector<pair<char, int>> groups;

        for (size_t i = 0; i < N;) {
            int j = i;

            while (j < N && word[i] == word[j])
                j++;

            groups.push_back({word[i], j - i});

            i = j;
        }

        set<string> possible;

        // Case 1 - No long press
        possible.insert(word);

        // Case 2 - Try reducing exactly one group with count > 1
        for (int i = 0; i < groups.size(); i++) {
            auto [ch, count] = groups[i];
            
            if(count == 1)
                continue;
            
            for(int reduceTo = 1; reduceTo < count; reduceTo++) {
                string temp = "";
                
                for(int j = 0; j < groups.size(); j++) {
                    if(j == i) {
                        temp += string(reduceTo, groups[j].first);
                    } else {
                        temp += string(groups[j].second, groups[j].first);
                    }
                }

                possible.insert(temp);
            }
        }
        
        return possible.size();
    }
};