class Solution {
public:
    // BruteForce - It is all about applying counting tricks
    // TLE 
     long long countGood1(vector<int>& nums, int k) {
        int N = nums.size();
        long long count = 0;

        for (int i = 0; i < N; i++) {
            unordered_map<int, int> freq;
            int pairs = 0;

            for (int j = i; j < N; j++) {
                pairs += freq[nums[j]];  // each existing occurrence of nums[j] contributes to a pair
                freq[nums[j]]++;

                if (pairs >= k) {
                    count++;
                }
            }
        }

        return count;
    }

    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long res = 0;
        int left = 0;
        long long pairs = 0;

        for (int right = 0; right < nums.size(); ++right) {
            int val = nums[right];

            // Each new same element creates `freq[val]` pairs
            pairs += freq[val];
            freq[val]++;

            // Shrink the window while we have enough pairs
            while (pairs >= k) {
                res += nums.size() - right;

                freq[nums[left]]--;
                pairs -= freq[nums[left]];
                left++;
            }
        }

        return res;
    }
};