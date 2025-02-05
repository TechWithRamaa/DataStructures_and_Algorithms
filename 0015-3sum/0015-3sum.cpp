class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        int leftPointer = 0;
        int rightPointer = nums.size() - 1;
        
        // -4, -1, -1, 0, 1, 2

        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i-1] == nums[i])
                continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum  = nums[i] + nums[left] +  nums[right];

                if(sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    while(left < right && nums[left] == nums[left + 1])
                       left++;

                    while(left < right && nums[right] == nums[right - 1])
                       right--;

                    left++;
                    right--;
                } else if (sum < 0) 
                    left++;
                 else 
                    right--;
            }
        }

        return result;
    }
};