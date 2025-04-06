class Solution {
public:
    // Approach 4
    // Cycle Detection (Floyd's Tortoise & Hare) - Very important
    // TC ~ O ( n )
    int findDuplicate4(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }

    // Approach 3
    // Binary Search on the Value Space - Very important
    // TC ~ O ( n log n )
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = getCount(nums, mid);

            if (count > mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    int getCount(vector<int>& nums, int mid) {
        int count = 0;
        for(int num : nums) {
            if(num <= mid) {
                count++;
            }
        }

        return count;
    }


    // Approach 2
    // Set
    // Extra memory - not allowed
    // TC ~ O ( n ) ; SC ~ O ( n )
    int findDuplicate2(vector<int>& nums) {
        unordered_set<int> s;

        for (auto num : nums) {
            if (s.count(num) > 0) {
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

        if (nums.size() == 2) {
            if (nums[0] == nums[1]) {
                return nums[0];
            }
        }

        for (int i = 1; i <= nums.size() - 1; i++) {
            if (nums[i] == nums[i - 1]) {
                return nums[i - 1];
            }
        }

        return -1;
    }
};