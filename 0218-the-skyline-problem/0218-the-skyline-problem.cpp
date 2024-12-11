class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
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
};