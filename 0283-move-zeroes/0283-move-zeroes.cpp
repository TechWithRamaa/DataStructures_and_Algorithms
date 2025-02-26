class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0; // Pointer for placing non-zero elements

        // Traverse the array
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]); // Swap non-zero element with the leftmost zero
                j++; 
            }
        }
    }
};