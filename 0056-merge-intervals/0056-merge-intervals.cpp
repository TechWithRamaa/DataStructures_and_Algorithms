class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> merged;
        
        for(vector<int>& current : intervals) {
            if(!merged.empty() && current[0] <= merged.back()[1]) {
                merged.back()[1] = max( current[1], merged.back()[1]);
            } else {
                merged.push_back(current);
            }
        }
        
        return merged;
    }
};