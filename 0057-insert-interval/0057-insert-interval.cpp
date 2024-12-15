class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0, n = intervals.size();

        // Add all intervals that end before the newInterval
        while (i < n && intervals[i][1] < newInterval[0]) 
            result.push_back(intervals[i++]);

        // Iteratively adjusts newInterval to encompass overlapping intervals
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        result.push_back(newInterval);

        // Add all intervals that come after the newInterval
        while (i < n) 
            result.push_back(intervals[i++]);

        return result;
    }
};