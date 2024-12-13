class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0); // To store the result counts
        vector<pair<int, int>> nums_with_indices(
            n); // To store the numbers with original indices

        // Store the numbers with their original indices
        for (int i = 0; i < n; ++i) {
            nums_with_indices[i] = {nums[i], i};
        }

        // Call merge sort to count the smaller elements during merging
        mergeSort(nums_with_indices, counts);

        return counts;
    }

private:
    // Merge Sort Helper function that counts the smaller elements during
    // merging
    void mergeSort(vector<pair<int, int>>& nums, vector<int>& counts) {
        vector<pair<int, int>> temp(nums.size());
        mergeSortHelper(nums, temp, 0, nums.size() - 1, counts);
    }

    void mergeSortHelper(vector<pair<int, int>>& nums,
                         vector<pair<int, int>>& temp, int left, int right,
                         vector<int>& counts) {
        if (left >= right) {
            return;
        }

        int mid = left + (right - left) / 2;
        mergeSortHelper(nums, temp, left, mid, counts);
        mergeSortHelper(nums, temp, mid + 1, right, counts);
        merge(nums, temp, left, mid, right, counts);
    }

    void merge(vector<pair<int, int>>& nums, vector<pair<int, int>>& temp,
               int left, int mid, int right, vector<int>& counts) {
        int i = left, j = mid + 1, k = left;
        int smaller_count = 0;

        // Merge the two halves while counting smaller elements for each number
        while (i <= mid && j <= right) {
            if (nums[i].first <= nums[j].first) {
                temp[k] = nums[i];
                counts[nums[i].second] += smaller_count;
                i++;
            } else {
                temp[k] = nums[j];
                smaller_count++;
                j++;
            }
            k++;
        }

        // Copy remaining elements from the left half
        while (i <= mid) {
            temp[k] = nums[i];
            counts[nums[i].second] += smaller_count;
            i++;
            k++;
        }

        // Copy remaining elements from the right half
        while (j <= right) {
            temp[k] = nums[j];
            j++;
            k++;
        }

        // Copy the merged array back to the original nums array
        for (int i = left; i <= right; ++i) {
            nums[i] = temp[i];
        }
    }
};