class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == 1)
            return 0; 

        vector<long long> adjacent_sums;
        for (int i = 0; i < n - 1; i++) {
            adjacent_sums.push_back(weights[i] + weights[i + 1]);
        }

        sort(adjacent_sums.begin(), adjacent_sums.end());

        long long min_sum = 0, max_sum = 0;
        for (int i = 0; i < k - 1; i++) {
            min_sum += adjacent_sums[i]; // Smallest k-1 pairs for min score
            max_sum +=
                adjacent_sums[n - 2 - i]; // Largest k-1 pairs for max score
        }

        return max_sum - min_sum;
    }
};