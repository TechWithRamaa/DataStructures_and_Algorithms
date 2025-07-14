class Solution {
public:
    string makeFancyString(string s) {
        string res;

        for(const auto& ch : s) {
            int L = res.length();
            if(L >= 2 && res[L-1] == ch && res[L-2] == ch)
                continue; 

            res += ch;
        }

        return res;
    }
};
     