class Solution {
public:
    // 5 approaches are there for solving this problem
    // depending the company & the depth required,
    // they ll dive into complex optimisitc approaches

    // 1 => BruteForce
    // 2 =>
    // 3 => Sorting
    // 4 => Binary Search [when values fall in a predictable range]
    // 5 => Counting Sort [when the range is small or known range]
    //

    // ~ O(n log k)
    int findKthLargest1(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> minHeap;

        for (auto num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        return minHeap.top();
    }

    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        return nums[k - 1];
    }

    // 4 => Binary Search [Best for scenarios where values fall in a predictable
    // range] TC ~ O(n * log(maxValue - minValue)) ; SC ~ O ( 1 )
    int findKthLargestBinarySearch(vector<int>& nums, int k) {

        int high = *max_element(nums.begin(), nums.end());
        int low = *min_element(nums.begin(), nums.end());

        if (k == 1)
            return high;

        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = getCountLargerOrEqualThanMid(nums, mid);

            if (count >= k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low - 1;
    }

    int getCountLargerOrEqualThanMid(vector<int>& nums, int mid) {
        int count = 0;

        for (int num : nums) {
            if (num >= mid)
                count++;
        }

        return count;
    }

    // 5 => Counting Sort [when the range is small or known range]
    // TC ~ O(n + maxValue) ; SC ~ O ( maxValue )
    int findKthLargestCountingSort(vector<int>& nums, int k) {
        int MAX_VALUE = 10;
        vector<int> freqVector(MAX_VALUE + 1, 0);

        for (int num : nums) {
            freqVector[num]++;
        }

        for (int i = MAX_VALUE; i >= 0; i--) {
            k -= freqVector[i];

            if (k <= 0)
                return i;
        }

        return -1; // invalid
    }
};