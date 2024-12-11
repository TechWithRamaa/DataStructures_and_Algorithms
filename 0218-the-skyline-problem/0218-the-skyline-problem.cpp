class Solution {
public:
    vector<vector<int>> getSkylineMultiSet(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events; // {x-coordinate, height (positive for
                                       // start, negative for end)}

        // Create events for all buildings
        for (const auto& building : buildings) {
            events.emplace_back(building[0], building[2]);  // Start event
            events.emplace_back(building[1], -building[2]); // End event
        }

        // Sort events
        sort(events.begin(), events.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 if (a.first != b.first)
                     return a.first < b.first; // Sort by x-coordinate
                 return a.second > b.second;   // Sort starts (positive heights)
                                               // before ends (negative heights)
             });

        // Resultant skyline
        vector<vector<int>> result;
        multiset<int> activeHeights = {
            0}; // Active heights, initialize with ground level

        int prevMaxHeight = 0; // Previous max height in the skyline

        // Process all events
        for (const auto& [x, h] : events) {
            if (h > 0) {
                // Start event: Add height
                activeHeights.insert(h);
            } else {
                // End event: Remove height
                activeHeights.erase(activeHeights.find(-h));
            }

            // Get current max height
            int currMaxHeight = *activeHeights.rbegin();

            // If the max height changes, add a new key point
            if (currMaxHeight != prevMaxHeight) {
                result.push_back({x, currMaxHeight});
                prevMaxHeight = currMaxHeight;
            }
        }

        return result;
    }

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> result;

        // Step 1: Create events
        vector<pair<int, int>> events;
        for (const auto& building : buildings) {
            events.push_back({building[0], building[2]});  // Start event
            events.push_back({building[1], -building[2]}); // End event
        }

        // Step 2: Sort events by x-coordinate
        sort(events.begin(), events.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 if (a.first == b.first)
                     return a.second > b.second;

                 return a.first < b.first;
             });

        // Max-heap to store the active building heights
        priority_queue<int> maxHeap;

        //(lazy deletion)
        map<int, int> heightCount; // Map to track invalid heights

        maxHeap.push(0); // Initial ground level

        int prevMaxHeight = 0;

        // Process each event
        for (const auto& event : events) {
            int x = event.first;
            int height = event.second;

            if (height > 0)
                maxHeap.push(height); // Start event: Add height to the heap
            else
                heightCount[-height]++; // End event: Mark height as ended

            // Clean the top of the heap if it's an invalid height
            while (!maxHeap.empty() && heightCount[maxHeap.top()] > 0) {
                heightCount[maxHeap.top()]--;
                maxHeap.pop();
            }

            // Get the current max height from the heap
            int currMaxHeight = maxHeap.top();

            // If the max height changes, add a new key point to the result
            if (currMaxHeight != prevMaxHeight) {
                result.push_back({x, currMaxHeight});
                prevMaxHeight = currMaxHeight;
            }
        }

        return result;
    }
};