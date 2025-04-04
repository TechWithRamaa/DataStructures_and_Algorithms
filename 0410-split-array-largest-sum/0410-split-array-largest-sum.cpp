class Solution {
private:

    bool canSplit(int guessedSum, int k, vector<int>& nums) {
        int splitCount = 1;
        int runningSum = 0;

        for(auto num : nums) {
            if(runningSum + num > guessedSum) {
                splitCount++;
                runningSum = num;
                
                if(splitCount > k)
                    return false;
            } else 
                runningSum += num;
        }

        return true;
    }

public:

    int splitArray(vector<int>& nums, int k) {
        
        int left = *max_element(nums.begin(), nums.end()); // minimum largest sum
        int right = accumulate(nums.begin(), nums.end(), 0); // maximum possible sum
 
        while(left < right) {
            int mid = left + ((right - left) / 2);

            if(canSplit(mid, k, nums)) 
                right = mid;  // try smaller maxSum
            else 
                left = mid + 1; // need larger maxSum
        }

        return left;
    }
};