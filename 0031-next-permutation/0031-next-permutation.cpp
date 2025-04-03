class Solution {
public:
    // Key Intuition
    /*
       Scan from right → find first drop (nums[i] < nums[i+1]).
       Find the smallest larger element in the right suffix & swap.
       Reverse the suffix to get the smallest next permutation.
    */
    void nextPermutation(vector<int>& nums) {
        int N = nums.size();
        int i = N - 2;

        // Find the first decreasing element
        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;

        if (i >= 0) {
            int j = N - 1;
            
            // Find the smallest largest element for i th element
            while (nums[j] <= nums[i])
                j--;

            // Swap the elements
            swap(nums[i], nums[j]);
        }

        // Reverse the suffix to get the lexicographically next largest
        reverse(nums.begin() + i + 1, nums.end());
    }
};