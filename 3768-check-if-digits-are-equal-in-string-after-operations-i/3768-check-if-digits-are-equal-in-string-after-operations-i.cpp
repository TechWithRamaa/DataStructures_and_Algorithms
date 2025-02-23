class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size() > 2) {
            string next;
            for(int i = 0; i < s.size() - 1; i++) {
                int sum = (s[i] - '0' + s[i+1] - '0') % 10;
                next.push_back(sum);
            }
            s = next;
        }

        return s[0] == s[1];
    }
};