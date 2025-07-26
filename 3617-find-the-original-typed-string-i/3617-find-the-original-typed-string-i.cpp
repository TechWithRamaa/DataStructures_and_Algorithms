class Solution {
public:
int possibleStringCount(string word) {
    vector<pair<char, int>> groups;
    int n = word.size();
    
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && word[j] == word[i]) j++;
        groups.push_back({word[i], j - i});
        i = j;
    }

    set<string> possible;

    // Case 1: No long press
    string original = "";
    for (auto [ch, cnt] : groups)
        original += string(cnt, ch);
    possible.insert(original);

    // Case 2: Try reducing exactly one group with count > 1
    for (int i = 0; i < groups.size(); ++i) {
        auto [ch, cnt] = groups[i];
        if (cnt == 1) continue;

        // Try all reduced sizes (from cnt-1 down to 1)
        for (int reduceTo = 1; reduceTo < cnt; ++reduceTo) {
            string temp = "";
            for (int j = 0; j < groups.size(); ++j) {
                if (j == i)
                    temp += string(reduceTo, groups[j].first);
                else
                    temp += string(groups[j].second, groups[j].first);
            }
            possible.insert(temp);
        }
    }

    return possible.size();
}

};