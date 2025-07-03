class Solution {
public:
    /*
    Key Observation
    The smaller the divisor → the larger each ceil(nums[i] / divisor) → total
    sum increases The larger the divisor → the smaller each ceiling → total sum
    decreases

    ✅ This is a monotonic function → you can use binary search!
    */
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int answer = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (isValid(nums, mid, threshold)) {
                answer = mid;
                right = mid - 1; // try smaller
            } else {
                left = mid + 1; // try larger
            }
        }

        return answer;
    }

private:
    bool isValid(const vector<int>& nums, int divisor, int threshold) {
        int sum = 0;
        for (int num : nums) {
            sum += (num + divisor - 1) / divisor; // ceiling division trick
        }
        return sum <= threshold;
    }
};