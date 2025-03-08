class Solution {
public:
    // Dyanmic Sized Sliding Window
    int longestOnes(vector<int>& nums, int k) {
        int maxConsecutiveOnes = 0;
        int start = 0, end = 0;
        int zeros = 0;

        for(end = 0; end < nums.size(); end++) {
            if(nums[end] == 0) {
                zeros++;
            }

            while(zeros > k) {
                if(nums[start] == 0)
                    zeros--;
                start++;
            }

            maxConsecutiveOnes = max(maxConsecutiveOnes, end - start + 1);
        }

        return maxConsecutiveOnes;
    }
};