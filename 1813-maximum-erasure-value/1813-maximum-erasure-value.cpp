class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int maximumScore = INT_MIN;

        unordered_set<int> uniqueSet;
        int start = 0, runningSum = 0;
        for(int end = 0; end < nums.size(); end++) {
            while(uniqueSet.count(nums[end])) {
                runningSum -= nums[start];
                uniqueSet.erase(nums[start]);
                start++;
            }

            uniqueSet.insert(nums[end]);
            runningSum += nums[end];
            maximumScore = max(maximumScore, runningSum);
        }   

        return maximumScore;
    }
};

