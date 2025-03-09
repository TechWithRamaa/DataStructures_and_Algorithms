class Solution {
public:
 
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int count = 0;
        int violationCount = 0;

        // Step 1: Initialize violation count for the first window
        for (int j = 0; j < k - 1; j++) {
            if (colors[j] == colors[j + 1]) {
                violationCount++;
            }
        }
        if (violationCount == 0) count++;

        // Step 2: Sliding window
        for (int i = 1; i < n; i++) {
            int prevOut = (i - 1) % n;      // Element going out
            int newIn = (i + k - 1) % n;    // Element coming in

            // Remove the effect of the outgoing element
            if (colors[prevOut] == colors[(prevOut + 1) % n]) {
                violationCount--;
            }

            // Add the effect of the incoming element
            if (colors[newIn] == colors[(newIn - 1 + n) % n]) {
                violationCount++;
            }

            // If no violations, this window is alternating
            if (violationCount == 0) count++;
        }

        return count;
    }

    int numberOfAlternatingGroups2(vector<int>& colors, int k) {
        int n = colors.size();
        int count = 0;

        // Function to check if a window of size k is alternating
        auto isAlternatingWindow = [&](int start) -> bool {
            for (int j = 0; j < k - 1; j++) {
                int curIdx = (start + j) % n;
                int nextIdx = (start + j + 1) % n;
                if (colors[curIdx] == colors[nextIdx]) {
                    return false; // Found two consecutive same colors → NOT
                                  // alternating
                }
            }
            return true;
        };

        // Sliding window over circular array
        for (int i = 0; i < n; i++) {
            if (isAlternatingWindow(i)) {
                count++;
            }
        }

        return count;
    }
};