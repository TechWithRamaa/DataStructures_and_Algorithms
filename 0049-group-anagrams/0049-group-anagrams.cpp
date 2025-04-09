class Solution {
public:
    // TC ~ N * ( M log M )
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for(auto s: strs) {
            string key = s;
            sort(key.begin(), key.end());
            groups[key].push_back(s);
        }

        vector<vector<string>> result;
        for(auto [key, valueList]: groups) {
            result.push_back(valueList);
        }

        return result;
    }
};