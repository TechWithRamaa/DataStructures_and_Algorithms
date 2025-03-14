class Solution {
public:
     long long maximumCandies(vector<int>& candies, long long k) {
        long long totalCandies = accumulate(candies.begin(), candies.end(), 0LL);

        // Edge case: Not enough candies for k children
        if (totalCandies < k) return 0;

        // Binary search range
        long long left = 1, right = *max_element(candies.begin(), candies.end());
        long long result = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            // Count how many children can get 'mid' candies each
            long long count = 0;
            for (auto& pile : candies) {
                count += pile / mid;
            }

            if (count >= k) { // Enough children can be satisfied
                result = mid;
                left = mid + 1; // Try for larger distribution
            } else {
                right = mid - 1; // Try for smaller distribution
            }
        }

        return result;
    }
};