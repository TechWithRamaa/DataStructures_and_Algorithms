class Solution {
    /*
    Our goal is to:

    Remove the minimum number of invalid parentheses to make the string valid.

    Return all unique valid strings formed with that minimum number of removals.

    So, we're finding all valid strings formed after minimum deletions, not just any valid one.

    Key idea:
    
    Start with the input string.

    At each level of BFS, remove one parenthesis at every possible position.

    Once we find valid strings, stop and return all valid strings at that level.
    */
private:
    bool isValidParenthesis(string &s) {
        int count = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(')
                count++;
            else if (s[i] == ')')
                count--;
            
            if(count < 0)
                return false;
        }

        return count == 0;
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> visited;
        vector<string> results;

        queue<string> q;
        q.push(s);
        visited.insert(s);

        bool foundValidString = false;

        while(!q.empty()) {
            string current = q.front();
            q.pop();

            if(isValidParenthesis(current)) {
                results.push_back(current);
                foundValidString = true;
            }    

            // once valid state is found, dont explore further
            if(foundValidString)
                continue;

            for(int i = 0; i < current.size(); i++) {
                char currentChar = current[i];

                if(currentChar != '(' && currentChar != ')')
                    continue;
                
                string next = current.substr(0, i) + current.substr(i + 1);

                if(!visited.count(next)) {
                    q.push(next);
                    visited.insert(next);
                }
            }
        }

        return results;
    }
};