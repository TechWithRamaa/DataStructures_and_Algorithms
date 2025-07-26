class Solution {
public:
    // using read & write pointers as in move non-zero elements to the front problem
    int compress(vector<char>& chars) {
        int write = 0, read = 0;
        int N = chars.size();

        while (read < N) {
            char currentChar = chars[read];
            int count = 0;

            // Count group length
            while (read < N && chars[read] == currentChar) {
                read++;
                count++;
            }

            // Write the character
            chars[write++] = currentChar;

            // Write the count if greater than 1
            if (count > 1) {
                string cnt = to_string(count);

                // if cnt is multi-digit, we need to write char by char
                for (char c : cnt) {
                    chars[write++] = c;
                }
            }
        }

        return write;
    }
};