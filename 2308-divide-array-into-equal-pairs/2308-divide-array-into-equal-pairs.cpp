class Solution {
public:
    // Approach 1
    // TC ~ O ( 2 * n ) ; SC ~ O ( n )
    bool divideArray1(vector<int>& nums) {
        unordered_map<int, int> freqMap;

        for (int num : nums) {
            freqMap[num]++;
        }

        for (auto [num, freq] : freqMap) {
            if (freqMap[num] % 2 != 0)
                return false;
        }

        return true;
    }

    // Approach 2
    // TC ~ O ( 2 * n ) ; SC ~ O ( 1 )
    bool divideArray(vector<int>& nums) {
        vector<int> freqVector(501, 0);

        for (int num : nums) {
            freqVector[num]++;
        }

        for (int freq : freqVector) {
            if (freq % 2 != 0)
                return false;
        }

        return true;
    }
};