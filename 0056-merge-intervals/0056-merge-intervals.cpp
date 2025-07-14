class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> merged;

        for(const auto& interval : intervals) {
            int start = interval[0], end = interval[1];

            if(!merged.empty() && start <= merged.back()[1]) {
                merged.back()[1] = max(merged.back()[1], end);
            } else {
                merged.push_back({start, end});
            }
        }

        return merged;
    }
};

//[1, 6],[8, 10],[15, 18]