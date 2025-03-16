class Solution {
public:
    // Binary Search on the Index Space
    // TC ~ O ( log n )
    // Same as LeetCode 162 - Find Peak Element
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size();

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] > arr[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};