class Solution {
public:
    // Approach 2 
    // Prefix Sum approach

    // Tranform this problem into Number of subarrays having exactly k sum 
    // by considering all odd numbers as 1 & even numbers as 0
    int numberOfSubarrays2(vector<int>& nums, int k) {
        int subArrayCount = 0, prefixSum = 0;

        // <k, v> => prefixSum, count 
        unordered_map<int, int> freq;
        freq[0] = 1; // Base case for zero prefix sum

        for (int num : nums) {
            prefixSum += (num % 2); 

            if (freq.find(prefixSum - k) != freq.end()) {
                subArrayCount += freq[prefixSum - k];
            }

            freq[prefixSum]++;
        }

        return subArrayCount;
    }

    // Approach 1 
    // Variable or Dynamic Sliding Window
    // Exactly K in a Sliding Window approach is difficult to solve
    // So we atMost formula to solve this challenge in Sliding Window
    int numberOfSubarrays(vector<int>& nums, int k) {
        // Helper function to count subarrays with at most 'k' odd numbers

        // Exactly K = AtMost(K) - AtMost(K - 1)
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

private:
    int atMostK(vector<int>& nums, int k) {
        int left = 0, oddCount = 0, subArrayCount = 0;

        for(int right = 0; right < nums.size(); right++) {
            oddCount += (nums[right] % 2); 

            while(oddCount > k) {
                oddCount -= (nums[left] % 2);
                left++;
            }

            subArrayCount += ( right - left + 1); 
        }

        return subArrayCount;
    }
};