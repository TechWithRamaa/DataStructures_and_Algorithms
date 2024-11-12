class Solution {
public:
    int threeSumClosest(vector<int>& nums, const int target) {
        std :: sort(nums.begin(),nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];

        for(int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];

                if(std :: abs(target - currentSum) < std :: abs(target - closestSum))
                    closestSum = currentSum;

                if(currentSum < target) left++;
                else if(currentSum > target) right--;
                else return target;
            }
        } 
        return closestSum;
    }
};