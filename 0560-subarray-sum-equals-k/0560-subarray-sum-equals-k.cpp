class Solution {
public:
    // very very high potential technique
    // works on negatives, zeroes, positives
    // window sliding will not work for negatives

    // prefix sum + hashmap
    // O ~ ( N ) - both TC & SC
    int subarraySum(const vector<int>& nums, const int k) {
        unordered_map<int, int> prefixSumCount;
        // map has this structure = <prefixSum, count>

        // sub-array with sum as zero exists and has 1 such sub-array (empty-sub-array)
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