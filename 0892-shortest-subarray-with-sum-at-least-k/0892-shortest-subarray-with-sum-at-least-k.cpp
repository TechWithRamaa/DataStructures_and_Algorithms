class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);

        // Prefix Sum
        for (int i = 0; i < n; ++i) 
            prefix[i + 1] = prefix[i] + nums[i];
        

        deque<int> dq; 
        int minLength = INT_MAX;

        for (int i = 0; i <= n; ++i) {
            // Check if we can form a valid subarray
            while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
                minLength = min(minLength, i - dq.front());
                dq.pop_front(); // Remove the front index
            }

            // Maintain deque in increasing order of prefix sums
            while (!dq.empty() && prefix[i] <= prefix[dq.back()]) 
                dq.pop_back(); // Remove indices that are no longer useful

            dq.push_back(i); // Add current index to deque
        }

        return minLength == INT_MAX ? -1 : minLength;
    }
};