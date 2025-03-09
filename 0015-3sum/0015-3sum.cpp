class Solution {
public:
    // key components to note are 

    // solution set should not contain duplicate triplets
    // one key idea to identify duplicates is when array is sorted
    // so we are SORTING the array
    
    // how we skip the duplicates
    // we can use while loop to skip until duplicates are bypassed

    // we reduce this problem from threeSum to (1Sum and 2Sum)
    // and we use 2 pointer approach for that 2Sum - subproblem
    
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