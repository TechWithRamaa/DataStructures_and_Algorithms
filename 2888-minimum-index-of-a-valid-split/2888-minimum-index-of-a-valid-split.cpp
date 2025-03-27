class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Find the dominant element using Boyer-Moore Voting Algorithm
        int candidate = -1, count = 0;
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        // Step 2: Count occurrences of the dominant element
        int totalCount = 0;
        for (int num : nums) {
            if (num == candidate) {
                totalCount++;
            }
        }

        // Step 3: Find the minimum valid split index
        int prefixCount = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == candidate) {
                prefixCount++;
            }

            // Check if `candidate` is dominant in both halves
            if (prefixCount * 2 > (i + 1) &&
                (totalCount - prefixCount) * 2 > (n - i - 1)) {
                return i;
            }
        }

        return -1; // No valid split found
    }
};