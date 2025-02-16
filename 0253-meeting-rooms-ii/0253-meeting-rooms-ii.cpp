class Solution {
public:
    // Sort + MinHeap => TC ~ O(n log n) + O (n log n)
    //                => SC ~ O(n) + O(n)
    int minMeetingRoomsHeap(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
 
        priority_queue<int, vector<int>, greater<>> minHeap;
        for(vector<int>& interval : intervals) {
            if(!minHeap.empty() && interval[0] >= minHeap.top()) {
                minHeap.pop();
            }
            
            minHeap.push(interval[1]);
        }
        
        return minHeap.size();
    }

    // Sweep Line Algorithm or Line Sweeping with Event Processing
    // Converts intervals into events
    // Sorts the events 
    // Counting active meetings by running a counter
    // TC ~ O (n log n) ; SC ~ O (n)
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int, int>> events;

        for(vector<int>& interval : intervals) {
            events.push_back({interval[0], 1});
            events.push_back({interval[1], -1});
        }

        sort(events.begin(), events.end(), [] (const pair<int, int>& a, const pair<int, int>& b) {
            if(a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;
        });

        int meetingRooms = 0, activeMeetings = 0;
        for(pair<int, int>& event : events) {
            activeMeetings += event.second;
            meetingRooms = max(meetingRooms, activeMeetings);
        }

        return meetingRooms;
    }
};