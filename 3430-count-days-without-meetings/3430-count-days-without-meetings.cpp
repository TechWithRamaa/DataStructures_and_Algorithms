class Solution {
public:
    // Approach 1 - BruteForce ; TC ~ O ( meetings + days) ; SC ~ O ( days )
    // Just use extra space to mark the meetings 
    // and make a count & subtract from the given days to arrive at the free days
    int countDays1(int days, vector<vector<int>>& meetings) {
        int meetingCount = 0;

        vector<bool> isMeetingScheduled(days + 1, false);
        for(auto& meeting : meetings) {
            for(int j = meeting[0]; j <= meeting[1]; j++)
                isMeetingScheduled[j] = true;
        }

        for(int i = 1; i <= days; i++) {
            cout << isMeetingScheduled[i];
            if(isMeetingScheduled[i])
                meetingCount++;
        }

        return days - meetingCount;
    }

    // Approach 2
    // Also TLE 
    int countDays2(int days, vector<vector<int>>& meetings) {
        int meetingCount = 0;

        unordered_set<int> isMeetingScheduled;
        for(auto& meeting : meetings) {
            for(int j = meeting[0]; j <= meeting[1]; j++)
                isMeetingScheduled.insert(j);
        }

        return days - isMeetingScheduled.size();
    }

    // Approach 3 
    // Sorting + Merging the overlapping meetings + counting the meetings
    // TC ~ O ( n log n + n )
    int countDays(int days, vector<vector<int>>& meetings) {
        int meetingCount = 0;

        sort(meetings.begin(), meetings.end());
        int start = meetings[0][0], end = meetings[0][1];

        for(int i = 1; i < meetings.size(); i++) {
            if(meetings[i][0] <= end) {
                // merging the Overlapping or contiguous interval
                end = max(end, meetings[i][1]);
            } else {
                meetingCount += (end - start) + 1;
                start = meetings[i][0], end = meetings[i][1];
            }
        }
        meetingCount += (end - start) + 1;

        return days - meetingCount;
    }
};