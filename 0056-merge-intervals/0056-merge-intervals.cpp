class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;

        for (const auto& interval : intervals) {
            // If merged list is empty or current interval does not overlap, add it
            if (merged.empty() || merged.back()[1] < interval[0])
                merged.push_back(interval);
            else
                // Overlapping intervals; merge them by updating the end time
                merged.back()[1] = max(merged.back()[1], interval[1]);
        }

        return merged;
    }
};