class Solution {
public:
    // Bounded Combinations 
    // At most 2 non-overlapping events
    // maximize the value not the no of events
    // fix the second event, choose the best first non-overlapping event by binary search
    // add the values and maximize it

    int maxTwoEvents(vector<vector<int>>& events) {
        // Sort events by end time for efficient binary search
        vector<pair<int, int>> sortedByEnd;
        for (auto& e : events) {
            sortedByEnd.push_back({e[1], e[2]}); // {end, value}
        }
        sort(sortedByEnd.begin(), sortedByEnd.end());

        // Build prefix max array
        vector<int> prefixMax(sortedByEnd.size());
        prefixMax[0] = sortedByEnd[0].second;
        for (int i = 1; i < sortedByEnd.size(); ++i) {
            prefixMax[i] = max(prefixMax[i - 1], sortedByEnd[i].second);
        }

        // Sort events by start time to try them as 2nd event
        sort(events.begin(), events.end());

        int result = 0;
        for (auto& e : events) {
            int start = e[0], value = e[2];

            // Binary search: latest event ending before current start
            int lo = 0, hi = sortedByEnd.size() - 1, idx = -1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (sortedByEnd[mid].first < start) {
                    idx = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            // Max of value of current + max value of non-overlapping event
            if (idx != -1) {
                result = max(result, value + prefixMax[idx]);
            }

            // Just taking current event alone
            result = max(result, value);
        }

        return result;
    }
};

/*
 Summary Pattern for These Problems:
    Sort the events
    Use binary search or heap to find best prior non-overlapping candidates
    Use prefix max to avoid scanning the left side every time
    Always compare taking 1 event vs 2 non-overlapping
*/