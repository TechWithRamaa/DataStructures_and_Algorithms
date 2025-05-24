class Solution {
public:
    // Scan through the string
    bool checkRecord(string s) {
        int lates = 0, absents = 0;

        for(auto ch : s) {
            if(ch == 'A') {
                absents++;
            }

            if(ch == 'L') {
                lates++;
            } else {
                lates = 0;
            }

            if(absents >= 2 || lates >= 3)
                return false;

        }

        return true;
    }
};