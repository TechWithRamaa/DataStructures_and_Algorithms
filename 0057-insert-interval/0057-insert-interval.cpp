class Solution {
public:
    /*
    Two intervals overlap if:
        interval A = [a1, a2]
        interval B = [b1, b2]

        They overlap if: b1 <= a2 && a1 <= b2

        intervals[i][0] <= newInterval[1]
    */
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        
        int i = 0, N = intervals.size();

        // adding non-overlapping intervals
        while(i < N && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }

        // merging overlapping intervals and adding to result
        while(i < N && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }

        result.push_back(newInterval);

        // adding non-overlapping intervals
        while(i < N) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};