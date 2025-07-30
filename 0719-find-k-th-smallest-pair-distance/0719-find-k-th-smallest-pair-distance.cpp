class Solution {
public:
    /*
    I don't know what the k-th smallest distance is,
    but I can guess a value d, and check if it's too small or too big based on the number of valid pairs it includes.
    */
     int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int low = 0;
        int high = nums[n - 1] - nums[0]; // max possible distance

        while (low < high) {
            int mid = low + (high - low) / 2;

            int count = countPairs(nums, mid);

            if (count >= k) {
                high = mid; // try smaller distance
            } else {
                low = mid + 1; // need more pairs, increase distance
            }
        }

        return low;
    }

private:
    // Count number of pairs with distance <= maxDist
    int countPairs(vector<int>& nums, int maxDist) {
        int count = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            while (nums[right] - nums[left] > maxDist) {
                ++left;
            }
            count += right - left;
        }

        return count;
    }
};