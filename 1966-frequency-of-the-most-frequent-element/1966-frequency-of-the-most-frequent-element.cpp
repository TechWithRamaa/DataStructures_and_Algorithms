class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // Operating on a sorted array
        
        long long sum = 0;             
        int left = 0, maxFreq = 0;   
        
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right]; // Expansion
            
            // Validation
            while (static_cast<long long>(nums[right]) * (right - left + 1) > sum + k) {
                sum -= nums[left]; // Shrinking
                left++;
            }
            
            maxFreq = max(maxFreq, right - left + 1);
        }
        
        return maxFreq;
    }
};