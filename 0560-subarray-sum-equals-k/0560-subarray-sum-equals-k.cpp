class Solution {
    // 4 or 5 approaches are available
    // BruteForce -> Approach 1 -> Nested loops -> TC ~ O ( n * n )
    // Optimized  -> Approach 2 -> Prefix Sum + HashMap ->TC ~ O ( n )
    // Optimized  -> Approach 3 -> Window Sliding -> TC ~ O ( n ) works only positives
    // Optimized for range queries -> Approach 4 -> Fenwick / Segment Tree -> O (N log N)
    // good for updates / queries
    
public:
    // very very high potential technique
    // works on negatives, zeroes, positives
    // window sliding will not work for negatives

    // prefix sum + hashmap
    // O ~ ( N ) - both TC & SC
    int subarraySum(const vector<int>& nums, const int k) {
       
        // map has this structure = <prefixSum, count>
        unordered_map<int, int> prefixSumCount;

        // sub-array with sum as zero exists and has 1 such sub-array (empty-sub-array)
        prefixSumCount[0] = 1;

        int subArrayCount = 0;
        int runningSum = 0;

        for(const auto& num: nums) {
            runningSum += num;

            // if any subarray exists with target sum k, this will execute
            if(prefixSumCount.find(runningSum - k) != prefixSumCount.end())
                subArrayCount += prefixSumCount[runningSum - k];

            prefixSumCount[runningSum]++;
        }

        return subArrayCount;
    }
};