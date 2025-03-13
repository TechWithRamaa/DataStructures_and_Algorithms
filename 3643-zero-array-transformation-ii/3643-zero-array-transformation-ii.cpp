class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        return minOperations(nums, queries);
    }
private:
     bool canTransform(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);  // Difference array

        // Create the difference array based on the first k queries
        for (int i = 0; i < k; i++) {
            int li = queries[i][0];
            int ri = queries[i][1];
            int vali = queries[i][2];

            diff[li] -= vali;
            if (ri + 1 < n) {
                diff[ri + 1] += vali;
            }
        }

        // Reconstruct the array from the difference array
        vector<long long> temp(nums.begin(), nums.end()); 
        for (int i = 0; i < n; i++) {
            if (i > 0) diff[i] += diff[i - 1];  // Reconstruct prefix sum
            temp[i] += diff[i];

            // If any element is still greater than zero, transformation failed
            if (temp[i] > 0) return false;
        }

        return true;  // All elements successfully reduced to zero
    }

    int minOperations(vector<int>& nums, vector<vector<int>>& queries) {
        int left = 0, right = queries.size(), ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;  // Binary search midpoint
            if (canTransform(nums, queries, mid)) {
                ans = mid;    // Possible answer, try reducing k further
                right = mid - 1;
            } else {
                left = mid + 1;  // Need more queries to zero the array
            }
        }

        return ans;
    }
};