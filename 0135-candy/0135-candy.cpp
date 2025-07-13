class Solution {
public:
    // Greedy in Two Passes
    // Time: O(N) ; Space: O(N)
    int candy(vector<int>& ratings) {
        int N = ratings.size();
        vector<long long> candies(N, 1);

        for(int i = 1; i < N; i++) {
            if(ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] + 1;
            }
        }

        for(int i = N - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i+1]) {
                candies[i] = max(candies[i], candies[i+1] + 1);
            }
        }

        return accumulate(candies.begin(), candies.end(), 0LL);
    }
};