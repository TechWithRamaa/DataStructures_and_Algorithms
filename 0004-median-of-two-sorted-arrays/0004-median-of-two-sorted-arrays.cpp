class Solution {
    // The most beautiful & interesting problem is here
    // Approach 1 -> Merging ( 2 pointer ) + finding Median
    // Approach 2 -> Balanced Heaps
    // Approach 3 -> Binary Search (since here inputs are static, so we can fix
    // the RANGE )
public:
    // Approach 3 -> TC ~ O (log min(m, n))

    double findMedianSortedArrays(const vector<int>& nums1,
                                  const vector<int>& nums2) {
        return nums1.size() > nums2.size() ? findMedian(nums2, nums1)
                                           : findMedian(nums1, nums2);
    }

private:
    double findMedian(const vector<int>& nums1, const vector<int>& nums2) {
        const int M = nums1.size();
        const int N = nums2.size();

        int low = 0, high = M;

        while (low <= high) {
            int i = (low + high) / 2;    // Partition index for nums1
            int j = (M + N + 1) / 2 - i; // Partition index for nums2

            // Edge cases: -∞ if out of bounds
            int maxLeftX = (i == 0) ? INT_MIN : nums1[i - 1];
            int minRightX = (i == M) ? INT_MAX : nums1[i];
            int maxLeftY = (j == 0) ? INT_MIN : nums2[j - 1];
            int minRightY = (j == N) ? INT_MAX : nums2[j];

            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                // Found the correct partition
                if ((M + N) % 2 == 0) {
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                } else {
                    return max(maxLeftX, maxLeftY);
                }
            } else if (maxLeftX > minRightY) {
                // Move `i` left
                high = i - 1;
            } else {
                // Move `i` right
                low = i + 1;
            }
        }
        return 0;
    }
};