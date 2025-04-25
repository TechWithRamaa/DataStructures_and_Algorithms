class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, long long> freq;
        freq[0] = 1; // base case: empty prefix
        int prefix = 0;
        long long count = 0;

        for (int num : nums) {
            if (num % modulo == k) {
                prefix++;
            }
            int target = (prefix - k + modulo) % modulo;

            if (freq.count(target)) {
                count += freq[target];
            }

            freq[prefix % modulo]++;
        }

        return count;
    }
};