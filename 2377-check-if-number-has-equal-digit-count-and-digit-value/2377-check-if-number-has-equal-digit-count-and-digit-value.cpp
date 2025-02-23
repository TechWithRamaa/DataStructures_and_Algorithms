class Solution {
public:
    bool digitCount(string num) {
        // index, count, number
        // index -> number
        // num[index] gives count of number
        // frequenceMap gives number, count

        // number, count
        unordered_map<char, int> freqMap;

        for(char c : num) {
            freqMap[c]++;
        }

        for (int i = 0; i < num.length(); i++) {
            int number = i + '0';
            int count = num[i] - '0';

            if(freqMap[number] != count) {
                return false;
            }
        }

        return true;
    }
};