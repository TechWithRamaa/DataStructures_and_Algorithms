class Solution {
public:
    // Fixed Sliding Window of k is expected to be maintained with the 
    // alternating group property
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int N = colors.size();
        int count = 0;
        int violationCount = 0;

        // Step 1: Initialize violation count for the first window
        for (int j = 0; j < k - 1; j++) {
            if (colors[j] == colors[j + 1]) {
                violationCount++;
            }
        }
        if (violationCount == 0)
            count++;

        // Step 2: Sliding window
        for (int i = 1; i < N; i++) {
            int prevOut = ((i - 1) + N) % N;   // Element going out
            int newIn = (i + k - 1) % N; // Element coming in

            // Remove the effect of the outgoing element
            if (colors[prevOut] == colors[(prevOut + 1) % N]) {
                violationCount--;
            }

            // Add the effect of the incoming element
            if (colors[newIn] == colors[(newIn - 1 + N) % N]) {
                violationCount++;
            }

            // If no violations, this window is alternating
            if (violationCount == 0)
                count++;
        }

        return count;
    }
};