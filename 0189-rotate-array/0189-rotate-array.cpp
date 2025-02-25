class Solution {
public:
    // Reverse approach ~ O ( n )
    void rotate2(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; 
        
        reverse(nums.begin(), nums.end());
        
        // Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);
        
        // Reverse the remaining n - k elements
        reverse(nums.begin() + k, nums.end());
    }

    // Cycle approach ~ O ( n ) 
    void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;  
    int count = 0; 
    
    for (int start = 0; count < n; start++) {
        int current = start;
        int prev = nums[start];
        
        do {
            int next = (current + k) % n;  
            swap(prev, nums[next]);
            current = next;
            count++;
        } while (start != current);
    }
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