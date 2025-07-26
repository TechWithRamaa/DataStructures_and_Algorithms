class Solution {
public:
    // Let dp[i] = the maximum number of envelopes we can nest ending at envelope i.
    /*
        We sort envelopes by:

        Increasing width
        If same width: decreasing height → to avoid nesting same-width envelopes
        After sorting, we only need to find the LIS of heights.
    */

    // Binary Seach 
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Step 1: Sort envelopes
        // Sort by width increasing, and for equal width, by height decreasing
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1]; // decreasing height for same width
            return a[0] < b[0]; // increasing width
        });

        // Step 2: Extract the heights
        vector<int> heights;
        for (auto& e : envelopes) {
            heights.push_back(e[1]);
        }

        // Step 3: Apply Longest Increasing Subsequence on heights
        vector<int> lis;
        for (int h : heights) {
            auto it = lower_bound(lis.begin(), lis.end(), h);
            if (it == lis.end()) {
                lis.push_back(h);
            } else {
                *it = h;  // Replace to maintain the smallest possible tail
            }
        }

        return lis.size();
    }

    int maxEnvelopesDP(vector<vector<int>>& envelopes) {
        // Step 1: Sort envelopes by width increasing, height decreasing
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int n = envelopes.size();
        vector<int> dp(n, 1);  // dp[i] = max number of envelopes ending at i

        int maxLen = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }

        return maxLen;
    }
};