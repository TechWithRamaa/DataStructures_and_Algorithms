class Solution {
public:
    int findLengthOfLCIS1(vector<int>& nums) {
       int maxLength = 1;

        int start = 0;
       for(int end = 1; end < nums.size(); end++) {
            if(nums[end] > nums[end - 1]) {
                maxLength = max(maxLength, end - start + 1);
            } else {
                start = end;
            }
       }


       return maxLength; 
    }

    int findLengthOfLCIS(vector<int>& nums) {
        int maxLength = 1;

        int start = 0;
        for(int end = 1; end < nums.size(); end++) {
            while(nums[end] <= nums[end-1] && start < end) {
                start++;
            }

            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
     }
};