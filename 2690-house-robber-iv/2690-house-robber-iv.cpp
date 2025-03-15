class Solution {
public:
    bool canRob(vector<int>& nums, int k, int capability) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= capability) {
                count++;
                i++; // Skip next house to ensure non-adjacency
            }
            if (count >= k)
                return true;
        }
        return false;
    }

    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (canRob(nums, k, mid)) {
                high = mid; // Try to minimize capability
            } else {
                low = mid + 1; // Increase capability to meet the condition
            }
        }

        return low;
    }
};