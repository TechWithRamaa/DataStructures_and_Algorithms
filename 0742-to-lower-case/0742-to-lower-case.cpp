class Solution {
public:
    string toLowerCase(string s) {
        string result;

        for(auto c : s) {
            if(isupper(c))
                result += tolower(c);
            else 
                result += c;
        }

        return result;
    }
};