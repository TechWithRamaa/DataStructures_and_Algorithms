class Solution {
public:
     int minKBitFlips(std::vector<int>& nums, int k) {
        int flips = 0;
        int flip_indicator = 0;
        std::queue<int> flip_positions;

        for (int i = 0; i < nums.size(); ++i) {
            // Remove flips that are out of the current window
            if (!flip_positions.empty() && flip_positions.front() == i) {
                flip_positions.pop();
                flip_indicator ^= 1;
            }

            // Determine if the current bit needs to be flipped
            if (nums[i] == flip_indicator) {
                // Check if a k-bit flip is possible
                if (i + k > nums.size()) {
                    return -1;
                }
                // Perform the flip
                flips++;
                flip_indicator ^= 1;
                flip_positions.push(i + k);
            }
        }

        return flips;
    }
};