class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
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
};