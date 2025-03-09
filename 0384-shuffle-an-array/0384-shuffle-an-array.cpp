class Solution {
private:
    vector<int> original; // Store original array
    vector<int> shuffled; // Store shuffled array
public:
    Solution(vector<int>& nums) {
        original = nums; // Save original array
        shuffled = nums; // Initialize shuffled array
    }

    vector<int> reset() {
        return original; // Reset to original order
    }

    //  Fisher-Yates Shuffle algorithm for generating a random permutation
    vector<int> shuffle() {
        int n = shuffled.size();
        for (int i = n - 1; i > 0; i--) {
            int j = rand() % (i + 1);       // Random index in range [0, i]
            swap(shuffled[i], shuffled[j]); // Swap elements
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */