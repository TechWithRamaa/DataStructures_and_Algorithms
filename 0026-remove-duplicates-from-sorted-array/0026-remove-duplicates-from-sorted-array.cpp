class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0; // Edge case: empty array

        int i = 0; // Pointer for unique elements
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) { // Found a new unique element
                i++;
                nums[i] = nums[j]; // Move the unique element forward
            }
        }
        return i + 1; // The number of unique elements
    }
};