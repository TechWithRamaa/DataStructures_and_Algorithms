class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;

        for (int i = 0; i < nums.size(); i++) {
            // Remove elements from front if they are out of the window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // Remove elements from the back if they are smaller than the
            // current element
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Add the current element's index to deque
            dq.push_back(i);

            // Start recording results once the first window is fully formed
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};