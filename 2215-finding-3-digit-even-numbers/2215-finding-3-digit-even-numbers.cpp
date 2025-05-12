class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int, int> freqMap;

        for (int d : digits) 
            freqMap[d]++;

        vector<int> result;

        for (int num = 100; num <= 998; num += 2) { // only even numbers
            int a = num / 100; // extract first digit
            int b = (num / 10) % 10; // extract second digit
            int c = num % 10; // extract third digit

            unordered_map<int, int> tempMap = freqMap;
            if (--tempMap[a] >= 0 && --tempMap[b] >= 0 && --tempMap[c] >= 0) {
                result.push_back(num);
            }
        }

        return result;
    }
};
