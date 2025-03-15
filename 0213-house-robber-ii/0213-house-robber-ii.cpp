class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();

        if(N == 1) {
            return nums[0];
        }

        return max(rob(0, N - 2, nums), rob(1, N - 1, nums));
    }
private:
    int rob(int start, int end, const vector<int>& nums) {
        int maxRob = 0;

        int secondLast = 0, last = 0;
        for(int i = start; i <= end; i++) {
            int rob = nums[i] + secondLast;
            int dontRob = last;

            maxRob = max(rob, dontRob);

            secondLast = last;
            last = maxRob;
        }

        return maxRob;
    }
};