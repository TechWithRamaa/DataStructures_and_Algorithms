class Solution {
public:
    // Merging Overlapping Intervals
    // Core Idea (Greedy + Sorting)
    //      Sorting the intervals by start time.
    //      Iterating through them and:
    //          If the current interval overlaps with the previous one (i.e., start ≤ previous end), merge them.
    //          Otherwise, simply add it to the result list.

    // TC -> Sorting: O(n log n) and Merging: O(n) => Total: O(n log n)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;

        for(const auto& current : intervals) {
            int start = current[0], end = current[1];

            if(!merged.empty() && start <= merged.back()[1]) {
                merged.back()[1] = max(merged.back()[1], end);
            } else {
                merged.push_back({start, end});
            }
        }

        return merged;
    }
};