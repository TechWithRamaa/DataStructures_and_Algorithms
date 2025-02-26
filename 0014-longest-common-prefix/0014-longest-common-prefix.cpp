class Solution {
public:
    // Approach 1 
    // Vertical Matching on all Strings
    // TC ~ O ( n * m )
    string longestCommonPrefix2(vector<string>& strs) {
        for(int i = 0; i < strs[0].size(); i++) {
            for(int j = 1; j < strs.size(); j++) {
                if(i >= strs[j].length() || strs[j][i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }

        return strs[0];
    }

    // Approach 2
    // Sorting every string
    // Matching only first & last string
    // TC ~ O (n log n + M)
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());

        string first = strs[0], last = strs.back();
        int i = 0;

        while(i < first.length() && first[i] == last[i]) {
            i++;
        } 

        return first.substr(0, i);
    }
};