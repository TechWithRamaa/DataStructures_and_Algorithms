class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());  // sort by start time

        // Min-heap for available room indices
        priority_queue<int, vector<int>, greater<>> available;
        for (int i = 0; i < n; ++i) available.push(i);

        // Min-heap of (endTime, room)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;

        vector<int> count(n, 0); // meeting count for each room

        for (auto& m : meetings) {
            long long start = m[0], end = m[1];

            // Free up rooms that are done
            while (!busy.empty() && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }

            if (!available.empty()) {
                int room = available.top(); available.pop();
                count[room]++;
                busy.push({end, room});
            } else {
                auto [endTime, room] = busy.top(); busy.pop();
                long long duration = end - start;
                count[room]++;
                busy.push({endTime + duration, room});
            }
        }

        int maxCount = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            if (count[i] > maxCount) {
                maxCount = count[i];
                ans = i;
            }
        }

        return ans;
    }
};
