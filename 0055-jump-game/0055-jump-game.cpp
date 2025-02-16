class Solution {
public:
    // approach 1 - recursion ~ O ( 2 ^ n)
    bool canJump(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return canJump(nums, 0, memo);
    }

private:
    bool canJump(vector<int>& nums, int index, vector<int>& memo) {
        if(index == nums.size() - 1) 
            return memo[index] = true;
        
        if(memo[index] != -1) 
            return memo[index];
        
        int maxJumpPosition = min(index + nums[index], (int) nums.size() - 1);
        
        for(int next = index + 1; next <= maxJumpPosition; next++) {
            if(canJump(nums, next, memo))
                return memo[index] = true;
        }
        
        return memo[index] = false;
    }
};