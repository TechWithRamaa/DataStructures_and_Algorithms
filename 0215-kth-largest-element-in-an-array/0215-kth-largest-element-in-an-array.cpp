class Solution {
public:
    // 5 approaches are there for solving this problem
    // depending the company & the depth required,
    // they ll dive into complex optimisitc approaches

    // 1 => Quick sort [when n is large & no extra space allowed]
    // 2 => MinHeap [when k is considerably smaller than n]
    // 3 => Sorting [when k is almost equal to n]
    // 4 => Binary Search [when values fall in a predictable range]
    // 5 => Counting Sort [when the range is small or known range]

    // Then END .. Choose wisely

    // 1 => Quick sort [when n is large & no extra space allowed]
    // Average TC ~ O ( n ) ; Worst TC ~ O ( n ^ 2) ; SC ~ O ( 1 )
    int partition(std::vector<int>& nums, int low, int high) {
        // Randomly choose a pivot
        int pivotIndex = low + rand() % (high - low + 1);
        std::swap(nums[pivotIndex], nums[high]); // Swap with the last element

        int pivot = nums[high];
        int i = low - 1;

        for (int j = low; j < high; ++j) {
            if (nums[j] <= pivot) {
                ++i;
                std::swap(nums[i], nums[j]);
            }
        }

        std::swap(nums[i + 1], nums[high]);
        return i + 1;
    }

    int quickSelect(std::vector<int>& nums, int low, int high, int k) {
        while (low <= high) {
            int pivotIndex = partition(nums, low, high);

            if (pivotIndex == k) {
                return nums[k];
            } else if (pivotIndex < k) {
                low = pivotIndex + 1;
            } else {
                high = pivotIndex - 1;
            }
        }

        return -1; // Should not reach here if input is valid
    }

    int findKthLargestQuickSelect(std::vector<int>& nums, int k) {
        int n = nums.size();
        return quickSelect(nums, 0, n - 1, n - k);
    }

    // 2 => MinHeap [when k is considerably smaller than n]
    // TC ~ O(n log k) ; SC ~ O (k)
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> minHeap;

        for (auto num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        return minHeap.top();
    }

    // 3 => Sorting [when input array is not huge]
    // TC ~ O ( N log N ) ; SC ~ depending on the sorting algo.
    int findKthLargestSorting(vector<int>& nums, int k) {
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