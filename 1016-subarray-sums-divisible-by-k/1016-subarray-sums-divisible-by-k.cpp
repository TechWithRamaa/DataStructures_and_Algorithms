class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> modMap;

        int result = 0;
        int runningSum = 0;
        modMap[0] = 1;

        for(auto num : nums) {
            runningSum += num;

            // Handles negative values safely
            // Always returns a number in [0, k-1]
            // Common trick used in hashing, prefix mod, and circular array problems.
            int mod = (runningSum % k + k) % k;
            if(modMap.count(mod))
                result += modMap[mod];

            modMap[mod]++; 
        }

        return result;
    }
};