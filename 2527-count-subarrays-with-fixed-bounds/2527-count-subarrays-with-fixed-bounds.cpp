class Solution {
public:
    /*
        Sliding Window with Position Tracking
        Tracking Last Occurrences
    */
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long ans = 0;
        int lastMin = -1, lastMax = -1, lastInvalid = -1;

        for (int i = 0; i < n; ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                lastInvalid = i;
            }
            if (nums[i] == minK) {
                lastMin = i;
            }
            if (nums[i] == maxK) {
                lastMax = i;
            }
            int validStart = min(lastMin, lastMax);
            if (validStart > lastInvalid) {
                ans += (validStart - lastInvalid); // <- core trick
            }
        }

        return ans;
    }
};