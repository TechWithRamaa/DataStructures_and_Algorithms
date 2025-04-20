class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        for(int i = 1; i < intervals.size(); i++) {
            // start time of i th meeting is less than ending of the previous meeting
            if(intervals[i][0] < intervals[i-1][1]) {
                return false;
            }
        }

        return true;
    }
};