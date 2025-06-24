class Solution {
public:
    // In Place
    // Two pointer 
    // TC ~ O ( N )
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] > nums[i]) { 
                i++;
                nums[i] = nums[j];  
                // at this point, i & j are pointing 
                // at the same duplicate number
            }
        }
        return i + 1; 
    }
};