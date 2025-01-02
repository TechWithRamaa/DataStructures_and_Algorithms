class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1; // smallest number we cannot currently form
        int patches = 0;    // number of patches added
        int i = 0;

        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                // If the current number can help extend the range, use it
                miss += nums[i];
                i++;
            } else {
                // Patch the array by adding `miss`
                miss += miss;
                patches++;
            }
        }

        return patches;
    }
};