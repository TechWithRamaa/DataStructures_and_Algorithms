class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int N = questions.size();

        vector<long long> dp(N + 1, 0);

        for(int i = N - 1; i >= 0; i--) {
            int points = questions[i][0];
            int nextIndex = i + questions[i][1] + 1;

            long long take = points + (nextIndex < N ? dp[nextIndex] : 0);
            long long notTake = dp[i + 1];

            dp[i] = max(take, notTake);
        }

        return dp[0];
    }
};