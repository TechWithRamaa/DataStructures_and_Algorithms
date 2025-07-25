class Solution {
public:
   

    void dfs(string& s, int start, vector<string>& path, vector<vector<string>>& result) {
        if (start == s.length()) {
            result.push_back(path);
            return;
        }

        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(s, start, end)) {
                path.push_back(s.substr(start, end - start + 1));
                dfs(s, end + 1, path, result);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int left, int right) {
         while (left < right) {
            if (s[left++] != s[right--]) 
                return false;
        }
        
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>> result;
        
        dfs(s, 0, path, result);
        return result;
    }
};
