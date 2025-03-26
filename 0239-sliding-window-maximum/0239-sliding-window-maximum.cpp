class Solution {
public:
    // we need to maintain largest in the window in the FRONT
    // we maintain a deque of indices

    // deque has handles like pop_front() and pop_back()
    // and also push_front() and push_back()

    // KEY CRUX - Monotonic Decreasing Deque

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;

        for (int i = 0; i < nums.size(); i++) {
            // Remove outgoing elements from the front of the window
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

    // How standard Window Sliding Template is applied here
    /*
       1) Remove outgoing element
       2) Add Incoming element
       3) Take the result from the current window 
    */
    
    // Deque handles to remember forever
    /*
        dq.pop_back()
        dq.pop_front()

        dq.push_back()

        dq.front()
        dq.back()
    */

};