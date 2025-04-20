/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/
/*
\U0001f4a1 If there are multiple gaps between merged intervals, 
    then there are multiple common free time intervals.
*/
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        vector<Interval> allIntervals;

        // 1️⃣ Flatten all employee schedules into one list
        for (auto& empSchedule : schedule) {
            for (auto& interval : empSchedule) {
                allIntervals.push_back(interval);
            }
        }

        // 2️⃣ Sort intervals based on start time
        sort(allIntervals.begin(), allIntervals.end(), [](Interval& a, Interval& b) {
            return a.start < b.start;
        });

        vector<Interval> result;

        // 3️⃣ Start tracking the end of merged intervals
        int prevEnd = allIntervals[0].end;

        for (int i = 1; i < allIntervals.size(); ++i) {
            // 4️⃣ If there's a gap, it's a free time
            if (allIntervals[i].start > prevEnd) {
                result.push_back(Interval(prevEnd, allIntervals[i].start));
            }

            // 5️⃣ Merge intervals by updating prevEnd to max
            prevEnd = max(prevEnd, allIntervals[i].end);
        }

        return result;
    }
};
