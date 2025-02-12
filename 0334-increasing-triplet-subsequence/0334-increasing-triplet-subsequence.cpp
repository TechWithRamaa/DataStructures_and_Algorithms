class Solution {
public:
    // TC ~ O(N)
    bool increasingTriplet(vector<int>& nums) {
        int smallest = INT_MAX, mid = INT_MAX;
        
        for(auto num : nums) {
            if(num <= smallest) {
                smallest = num;
            } else if (num <= mid) {
                mid = num;
            } else {
                return true;
            }
        }
        
        return false;
    }
};