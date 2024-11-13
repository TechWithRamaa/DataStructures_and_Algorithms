class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std ::vector<std ::vector<int>> triplets;

        std ::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1, right = nums.size() - 1;

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            while (left < right) {
                int tripletSum = nums[i] + nums[left] + nums[right];

                if (tripletSum == 0) {
                    triplets.push_back({nums[i], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                } else if (tripletSum < 0)
                    left++;
                else
                    right--;
            }
        }
        return triplets;
    }
};