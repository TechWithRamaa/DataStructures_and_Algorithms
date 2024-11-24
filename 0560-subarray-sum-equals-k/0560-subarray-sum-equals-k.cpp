class Solution {
public:
    int subarraySum(const vector<int>& nums, const int k) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;

        int count = 0;
        int currentSum = 0;

        for(const auto& num: nums) {
            currentSum += num;
            if(prefixSumCount.find(currentSum - k) != prefixSumCount.end())
                count += prefixSumCount[currentSum - k];

            prefixSumCount[currentSum]++;
        }

        return count;
    }
};