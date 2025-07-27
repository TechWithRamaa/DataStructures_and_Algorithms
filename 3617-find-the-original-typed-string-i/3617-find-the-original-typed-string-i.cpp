class Solution {
public:
    int possibleStringCount(string word) {
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
        string original = "";
        for (auto& [ch, count] : groups) {
            original += string(count, ch);
        }

        possible.insert(original);

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