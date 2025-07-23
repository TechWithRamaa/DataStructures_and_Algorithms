class Solution {
public:
    bool backspaceCompare(string s, string t) {
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
};