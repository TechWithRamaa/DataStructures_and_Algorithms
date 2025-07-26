class Solution {
public:
    /*
    Pattern: Two Pointer - Overwrite Style

    Related to: Move Zeros, Remove Duplicates from Sorted Array

    Key trick: Don’t care what's beyond index k, just make sure the first k values are valid.
    */
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // index for placing valid elements
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i]; // overwrite
                k++;
            }
        }
        return k;
    }
};