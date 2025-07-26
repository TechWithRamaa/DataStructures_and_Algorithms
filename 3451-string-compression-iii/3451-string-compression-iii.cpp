class Solution {
public:
    string compressedString(string s) {
        string result;
        int N = s.length();
        int i = 0;

        while (i < N) {
            char currentChar = s[i];
            int count = 1;
            int j = i + 1;

            // Count how many same characters are there
            while (j < N && s[j] == currentChar) {
                count++;
                j++;
            }

            // Write in chunks of at most 9
            while (count > 0) {
                int writeCount = min(9, count);
                result += to_string(writeCount) + currentChar;
                count -= writeCount;
            }

            i = j;  // Move to next group
        }

        return result;
    }
};
