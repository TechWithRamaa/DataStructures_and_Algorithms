class Solution {
public:
    // int numberOfSubarrays(vector<int>& nums, int k) {
    //     int noOfSubarrays = 0;
    //     int oddCount = 0;

    //     int left = 0;
    //     for (int right = 0; right < nums.size(); right++) {
    //         if (nums[right] % 2 != 0) {
    //             oddCount++;
    //         }

    //         while (oddCount > k) {
    //             if (nums[right] % 2 != 0) {
    //                 oddCount--;
    //             }
    //             left++;
    //         }

    //         noOfSubarrays += (right - left + 1); // Count all valid subarrays
    //     }

    //     return noOfSubarrays;
    // }

    int numberOfSubarrays(vector<int>& nums, int k) {
    int count = 0, prefixSum = 0;
    unordered_map<int, int> freq;
    freq[0] = 1;  // Base case for zero prefix sum
    
    for (int num : nums) {
        prefixSum += (num % 2); // Odd → 1, Even → 0
        
        // Check if prefixSum - k exists
        if (freq.find(prefixSum - k) != freq.end()) {
            count += freq[prefixSum - k];
        }

        // Update frequency map
        freq[prefixSum]++;
    }

    return count;
}
};