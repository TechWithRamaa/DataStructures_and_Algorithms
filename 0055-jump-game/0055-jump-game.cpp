class Solution {
public:
    // approach 1 - recursion dp ~ O ( 2 ^ n) 
    bool canJumpDP(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return canJump(nums, 0, memo);
    }

    // approach 2 - greedy ~ O ( n )
    bool canJump(vector<int>& nums) {
        int farthest = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(i > farthest) 
                return false;
            
            farthest = max(farthest, i + nums[i]);

            if(farthest >= nums.size() - 1)
                return true;
        }

        return false;
    }

private:
    bool canJump(vector<int>& nums, int index, vector<int>& memo) {
        if(index == nums.size() - 1) 
            return memo[index] = 1;
        
        if(memo[index] != -1) 
            return memo[index];
        
        int maxJumpPosition = min(index + nums[index], (int) nums.size() - 1);
        
        for(int next = index + 1; next <= maxJumpPosition; next++) {
            if(canJump(nums, next, memo))
                return memo[index] = 1;
        }
        
        return memo[index] = 0;
    }
};