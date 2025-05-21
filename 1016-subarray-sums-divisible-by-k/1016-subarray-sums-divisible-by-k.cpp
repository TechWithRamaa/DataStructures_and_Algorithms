class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> modMap;

        int result = 0;
        int runningSum = 0;
        modMap[0] = 1;

        for(auto num : nums) {
            runningSum += num;

            int mod = (runningSum % k + k) % k;
            if(modMap.count(mod))
                result += modMap[mod];

            modMap[mod]++; 
        }

        return result;
    }
};