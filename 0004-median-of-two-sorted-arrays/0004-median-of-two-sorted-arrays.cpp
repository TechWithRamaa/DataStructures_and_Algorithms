class Solution {
public:
    double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
        return nums1.size() > nums2.size() ? findMedian(nums2, nums1) : findMedian(nums1, nums2);
    }

private:
    double findMedian(const vector<int>& nums1, const vector<int>& nums2) {
        const int M = nums1.size();
        const int N = nums2.size();

        int low = 0, high = M;

        while (low <= high) {
            int cut1 = low + (high - low) / 2;
            int cut2 = (M + N + 1) / 2 - cut1;

            int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int right1 = (cut1 == M) ? INT_MAX : nums1[cut1];

            int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int right2 = (cut2 == N) ? INT_MAX : nums2[cut2];

            if (left1 <= right2 && left2 <= right1) { // validates if sorting order is ensured
                if ((M + N) % 2 == 0)   
                    return (double) ((max(left1, left2) + min(right1, right2)) / 2.0); // even no of elements in logical merged array
                else
                    return (double) (max(left1, left2)); // odd no of elements in logical merged array
            } else if (left1 > right2)
                high = cut1 - 1; // Consider left half by adjusting high
            else
                low = cut1 + 1; // Consider right half by adjusting low
        }
        return 0;
    }
};