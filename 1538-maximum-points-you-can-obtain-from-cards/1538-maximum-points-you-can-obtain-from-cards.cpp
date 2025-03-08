class Solution {
public:
    // Approach 1
    // Problem transformed into Fixed Sliding Window
    /* Intuition for reframing the problem
    By reframing the problem to find the contiguous subarray of length \U0001d45b − \U0001d458
    with the minimum sum, you've transformed it into a fixed sliding window
    problem

    The minimum sum found within these windows tells you which block to leave
    behind, so that the sum of the removed cards (which is the total sum minus
    this minimum sum) is maximized.
    */
    int maxScore1(vector<int>& cardPoints, int k) {
        int windowSize = cardPoints.size() - k;

        int totalSum = 0;
        for (auto point : cardPoints) {
            totalSum += point;
        }

        int subArraySum = 0;
        for (int i = 0; i < windowSize; i++) {
            subArraySum += cardPoints[i];
        }

        int maxPoints = totalSum - subArraySum;

        for (int end = windowSize; end < cardPoints.size(); end++) {
            subArraySum -= cardPoints[end - windowSize];
            subArraySum += cardPoints[end];

            maxPoints = max(totalSum - subArraySum, maxPoints);
        }

        return maxPoints;
    }

    /*  Approach 2
    */
    int maxScore(vector<int>& cardPoints, int k) {
         int n = cardPoints.size();

        // Initially, take all k cards from the right end.
        int currentScore = 0;
        for (int i = n - k; i < n; i++) {
            currentScore += cardPoints[i];
        }
        
        int maxScore = currentScore;
        
        // Try taking cards from the left instead one by one.
        // x is the number of cards taken from the left, and k - x from the right.
        for (int x = 0; x < k; x++) {
            currentScore = currentScore - cardPoints[n - k + x] + cardPoints[x];
            maxScore = max(maxScore, currentScore);
        }
        
        return maxScore;
    }

   
};