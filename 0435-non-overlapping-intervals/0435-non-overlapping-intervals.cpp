class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });

        int count = 0;
        int previousEndTime = INT_MIN;

        for(auto& interval: intervals) {
            int start = interval[0], end = interval[1];

            if(start >= previousEndTime) {
                previousEndTime = end;
            } else {
                cout << start << " - " << end << " - " << previousEndTime << endl;
                count++;
            }
        }

        return count;
    }
};