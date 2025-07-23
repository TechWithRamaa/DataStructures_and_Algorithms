class Solution {
public:
    // takes extra space, hence not optimized
    bool backspaceCompareB(string s, string t) {
        string temp1;
        for(auto& ch : s) {
            if(ch == '#') {
                if(!temp1.empty())
                    temp1.pop_back();
            } else 
                temp1.push_back(ch);
        }

        string temp2;
        for(auto& ch : t) {
            if(ch == '#') {
                if(!temp2.empty())
                    temp2.pop_back();
            } else 
                temp2.push_back(ch);
        }

        return temp1 == temp2;
    }

    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1;
        int skipS = 0, skipT = 0;
        
        while (i >= 0 || j >= 0) {
            // Process backspaces in s
            while (i >= 0) {
                if (s[i] == '#') { 
                    skipS++; 
                    i--;
                }
                else if (skipS > 0) { 
                    skipS--; 
                    i--; 
                }
                else 
                    break;
            }

            // Process backspaces in t
            while (j >= 0) {
                if (t[j] == '#') { 
                    skipT++; 
                    j--; 
                }
                else if (skipT > 0) { 
                    skipT--; 
                    j--; 
                }
                else 
                    break;
            }

            // Compare current characters
            if (i >= 0 && j >= 0 && s[i] != t[j]) 
                return false;

            if ((i >= 0) != (j >= 0)) 
                return false; // One string ended

            i--;
            j--;
        }
        
        return true;
    }
};