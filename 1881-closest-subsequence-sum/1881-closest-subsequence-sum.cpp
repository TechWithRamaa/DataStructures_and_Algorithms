class Solution {
private:
    vector<int> generateSubsetSum(vector<int>& nums) {
        int N = nums.size();
        vector<int> res;
        int totalSubsets = 1 << N; // 2^N subsets

        for (int mask = 0; mask < totalSubsets; ++mask) {
            int sum = 0;
            for (int i = 0; i < N; i++) {
                if (mask & (1 << i)) {
                    sum += nums[i];
                }
            }
            res.push_back(sum);
        }

        return res;
    }

    int findClosest(int goal, vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int closest = nums[0];

        while (left <= right) {
            int mid = left + ((right - left) / 2);

            int diffMid = abs(nums[mid] - goal);
            int diffClosest = abs(closest - goal);

            if (diffMid < diffClosest)
                closest = nums[mid];
            else if (diffMid == diffClosest && nums[mid] < closest)
                closest = nums[mid];

            if (nums[mid] < goal)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return closest;
    }

public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int N = nums.size();

        vector<int> leftHalf(nums.begin(), nums.begin() + (N / 2));
        vector<int> rightHalf(nums.begin() + (N / 2), nums.end());

        vector<int> leftSums = generateSubsetSum(leftHalf);
        vector<int> rightSums = generateSubsetSum(rightHalf);

        sort(rightSums.begin(), rightSums.end());

        int minAbsDiff = INT_MAX;

        for (int leftSum : leftSums) {
            int target = goal - leftSum;
            int closestRight = findClosest(target, rightSums);

            int currentSum = closestRight + leftSum;

            minAbsDiff = min(minAbsDiff, abs(goal - currentSum));
        }

        return minAbsDiff;
    }
};