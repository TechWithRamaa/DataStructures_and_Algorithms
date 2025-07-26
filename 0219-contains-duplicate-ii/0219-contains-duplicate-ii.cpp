class Solution {
public:
    // Fixed Sliding Window in Disguise
    // To Note => abs(i - j) <= k
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;

        for (int i = 0; i < nums.size(); ++i) {
            if (window.count(nums[i]))
                return true;

            window.insert(nums[i]);

            // Maintain window size of at most k
            if (i >= k) {
                window.erase(nums[i - k]); // remove outgoing element
            }
        }

        return false;
    }
};