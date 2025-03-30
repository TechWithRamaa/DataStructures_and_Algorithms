class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int N = nums.size();

        // indexes are maintained here
        vector<int> pse(N, 0);
        vector<int> nse(N, N);

        vector<long long> prefixSum(N + 1, 0);

        for (int i = 0; i < N; i++)
            prefixSum[i + 1] = prefixSum[i] + nums[i];

        stack<int> st;

        // Previous Smaller Elements
        for (int i = 0; i < N; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();

            if (!st.empty())
                pse[i] = st.top() + 1;

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Next Smaller Elements
        for (int i = N - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();

            if (!st.empty())
                nse[i] = st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        long long maxValue = 0, MOD = 1e9 + 7;

        for (int i = 0; i < N; i++) {
            int left = pse[i];
            int right = nse[i];

            long long currentMinProduct =
                nums[i] * (long long)(prefixSum[right] - prefixSum[left]);

            maxValue = max(maxValue, currentMinProduct);
        }
        return maxValue % MOD;
    }
};