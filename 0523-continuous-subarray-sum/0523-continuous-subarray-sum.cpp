class Solution {
public:
    // Saving prefix sums (or mod of prefix sums) in a HashMap.
    bool checkSubarraySum(vector<int>& nums, int k) {
        int N = nums.size();

        int prefixSum = 0;
        unordered_map<int, int> modIndex;
        modIndex[0] = -1;

        for (int i = 0; i < N; i++) {
            prefixSum += nums[i];
            int mod = (k == 0) ? prefixSum : prefixSum % k;

            if (modIndex.count(mod)) {
                if (i - modIndex[mod] >= 2)
                    return true;
            } else
                modIndex[mod] = i;
        }

        return false;
    }
};