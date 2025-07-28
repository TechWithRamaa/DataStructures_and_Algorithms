class Solution {
public:
    long long maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        // sort by start time
        sort(events.begin(), events.end());

        // dp[i][j] = max total value using events[i..n-1] with j picks left
        vector<vector<long long>> dp(n+1, vector<long long>(k+1, 0));

        // iterate in reverse so dp[i+1][*] and dp[*][j-1] are ready
        for (int i = n-1; i >= 0; i--) {
            for (int j = 1; j <= k; j++) {
                // 1) skip this event
                long long best = dp[i+1][j];

                // 2) take this event, then jump to next non-overlapping
                //    binary search for first event whose start > events[i][1]
                int lo = i+1, hi = n, nextIdx = n;
                while (lo < hi) {
                    int mid = lo + (hi - lo)/2;
                    if (events[mid][0] > events[i][1]) {
                        nextIdx = mid;
                        hi = mid;
                    } else {
                        lo = mid+1;
                    }
                }

                long long take = (long long)events[i][2] + dp[nextIdx][j-1];
                dp[i][j] = max(best, take);
            }
        }

        return dp[0][k];
    }
};



/*
\U0001f539 Problem Summary:
    You’re given a list of events where each event has:
    startDay, endDay, and value.
    You can attend at most k non-overlapping events.

    Goal: Maximize the total value of the events attended.

\U0001f539 Approach: DP + Binary Search (on end time)
    This is a classic DP on sorted intervals problem. For each event, you decide:
    Take it and move to the next non-overlapping event.
    Skip it and try the next.

\U0001f539 Steps:
    Sort the events by start time.
    Use DP[i][k] to represent the maximum value using events from i onward with k picks left.
    Use binary search to jump to the next non-overlapping event.
*/