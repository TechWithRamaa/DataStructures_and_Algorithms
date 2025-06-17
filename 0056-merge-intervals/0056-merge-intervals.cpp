class Solution {
public:
    // Merging Overlapping Intervals
    // Core Idea (Greedy + Sorting)
    //      Sorting the intervals by start time.
    //      Iterating through them and:
    //          If the current interval overlaps with the previous one (i.e., start ≤ previous end), merge them.
    //          Otherwise, simply add it to the result list.
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> merged;
        
        for(vector<int>& current : intervals) {
            if(!merged.empty() && current[0] <= merged.back()[1]) {
                merged.back()[1] = max(current[1], merged.back()[1]);
            } else {
                merged.push_back(current);
            }
        }
        
        return merged;
    }
};