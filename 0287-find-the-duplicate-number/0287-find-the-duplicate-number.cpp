class Solution {
public:

    // Approach 3
    // Binary Search on the Value Space - Very important
    // TC ~ O ( n log n ) 
    int findDuplicate(vector<int>& nums) {
       int left = 1 , right = nums.size() - 1;

       while(left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;

            for(int num : nums) {
                if(num <= mid) {
                    count++;
                }
            }

            if(count > mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
       }

       return left;
    }

    // Approach 2
    // Set 
    // Extra memory - not allowed
    // TC ~ O ( n ) ; SC ~ O ( n )
    int findDuplicate2(vector<int>& nums) {
       unordered_set<int> s;

        for(auto num : nums) {
            if(s.count(num) > 0) {
                return num;
            }
            s.insert(num);
        }

        return -1;
    }

    // Approach 1 
    // BruteForce 
    // Alter the orginal array - not allowed
    // TC ~ O ( n log n )
    int findDuplicate1(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        if(nums.size() == 2) {
            if(nums[0] == nums[1]) {
                return nums[0];
            }
        }

        for(int i = 1; i <= nums.size() - 1; i++) {
            if(nums[i] == nums[i-1]) {
                return nums[i-1];
            }
        }

        return -1;
    }
};