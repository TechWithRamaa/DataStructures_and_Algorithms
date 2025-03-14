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
        int N = cardPoints.size();
        int totalSum = accumulate(cardPoints.begin(), cardPoints.end(), 0);

        if (k == N) return totalSum;

        int windowSize = N - k;  // Window size for the cards we are NOT picking
        int minWindowSum = accumulate(cardPoints.begin(), cardPoints.begin() + windowSize, 0);

        int currentWindowSum = minWindowSum;
        for (int i = windowSize; i < N; i++) {
            currentWindowSum -=  cardPoints[i - windowSize];
            currentWindowSum += cardPoints[i];

            minWindowSum = min(minWindowSum, currentWindowSum);
        }

        return totalSum - minWindowSum;
    }

    /*  Approach 2
    if you need to pick k cards, you can take 
    x cards from the left and k−x cards from the right. 
    Then, you simply compute the sum for each combination and take the maximum.
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
            currentScore -= cardPoints[n - k + x];
            currentScore += cardPoints[x];
            maxScore = max(maxScore, currentScore);
        }
        
        return maxScore;
    }
   
};