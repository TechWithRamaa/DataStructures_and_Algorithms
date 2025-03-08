class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int windowSize = cardPoints.size() - k;
        
        int totalSum = 0;
        for(auto point : cardPoints) {
            totalSum += point;
        }

        int subArraySum = 0;
        for(int i = 0; i < windowSize; i++) {
            subArraySum += cardPoints[i];
        }

        int maxPoints = totalSum - subArraySum;

        for(int end = windowSize; end < cardPoints.size(); end++) {
            subArraySum -= cardPoints[end - windowSize];
            subArraySum += cardPoints[end];

            maxPoints = max(totalSum - subArraySum, maxPoints);
        }

        return maxPoints;
     }
};