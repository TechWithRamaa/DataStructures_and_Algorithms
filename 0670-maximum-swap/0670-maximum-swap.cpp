class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();

        // Store the last occurrence of each digit
        vector<int> lastIndex(10, -1);
        for (int i = 0; i < n; i++)
            lastIndex[s[i] - '0'] = i;

        // Find the first smaller digit that can be swapped with a larger one
        for (int i = 0; i < n; i++) {
            for (int d = 9; d > s[i] - '0'; d--) {
                if (lastIndex[d] > i) {
                    // Swap and return result
                    swap(s[i], s[lastIndex[d]]);
                    return stoi(s);
                }
            }
        }
        return num;
    }
};