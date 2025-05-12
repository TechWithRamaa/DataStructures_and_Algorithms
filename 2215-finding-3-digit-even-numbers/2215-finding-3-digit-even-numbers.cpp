class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int, int> freqMap;

        for(int num : digits) {
           freqMap[num]++; 
        }

        vector<int> result;
        for(int num = 100; num < 1000; num++) {
            int temp = num;
            bool isPossible = true;
            unordered_map<int, int> tempFreqMap = freqMap;

            while(temp) {
                int digit = temp % 10;
                
                if(tempFreqMap[digit] > 0) {
                    tempFreqMap[digit]--;
                    temp = temp / 10;
                } else {
                    isPossible = false;
                    break;
                }
            }

            if(isPossible && ((num % 2) == 0)) {
                result.push_back(num);
            }
        }


        sort(result.begin(), result.end());

        return result;
    }
};