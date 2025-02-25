class Solution {
public:
    // Reverse approach ~ O ( n )
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; 
        
        reverse(nums.begin(), nums.end());
        
        // Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);
        
        // Reverse the remaining n - k elements
        reverse(nums.begin() + k, nums.end());
    }

    // BruteForce ~ O ( n )
    void rotateApproach1(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Adjust k if k >= n
        vector<int> temp(n);

        for (int i = 0; i < n; i++) {
            temp[(i + k) % n] = nums[i];
        }

        nums = temp;
    }

};