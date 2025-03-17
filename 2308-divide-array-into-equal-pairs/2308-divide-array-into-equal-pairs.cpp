class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> freqMap;

        for(int num : nums) {
            freqMap[num]++;
        }

        for(auto [num, freq] : freqMap) {
            if(freqMap[num] % 2 != 0) 
                return false;
        }

        return true;
    }
};