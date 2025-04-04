/*
    \U0001f50d Problem Summary:
    You are given an array nums and an integer k.
    Split the array into k non-empty subarrays such that the largest sum among these subarrays is minimized.
    Return that minimized largest sum.
*/
class Solution {
private:
    /*
    \U0001f4a1 Binary Search Logic:
     We’re searching for the minimum possible max sum across k splits.
     If it's possible to split with a max sum of mid, try smaller (right = mid).
     If not possible, go higher (left = mid + 1).
     We stop at left == right which gives the minimum possible valid largest sum.
    */
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
    // Guess Game - guess the minimized maximum sum
    // Binary Search + Prefix Sum + Greedy for paritioning
    // TC ~ O ( N * log (max sum))
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