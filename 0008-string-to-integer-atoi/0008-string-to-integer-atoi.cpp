class Solution {
public:
    int myAtoi(string s) {
        if(s.empty()) return 0;

        long result = 0;
        int n = s.length();

        int i = 0;
        while(i < n && s[i] == ' ') {
            i++;
        }

        int sign = 1;
        if(i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        

        while(i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            if(result * sign > INT_MAX) {
                return INT_MAX;
            }

            if(result * sign < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }
        return result * sign;
    }
};