class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source,
                              int target) {
        if (source == target)
            return 0;

        int n = routes.size();

        // Step 1: Map each bus stop to the buses it is part of
        unordered_map<int, vector<int>> stopToBuses;
        for (int i = 0; i < n; ++i) {
            for (int stop : routes[i]) {
                stopToBuses[stop].push_back(i);
            }
        }

        // Step 2: BFS to find the shortest path from source to target
        queue<int> q;
        unordered_set<int> visitedStops; // To keep track of visited bus stops
        unordered_set<int> visitedBuses; // To avoid revisiting the same bus

        // Initialize BFS with the source bus stop
        q.push(source);
        visitedStops.insert(source);
        
        int busesTaken = 0;

        while (!q.empty()) {
            int size = q.size();
            ++busesTaken;

            for (int i = 0; i < size; ++i) {
                int stop = q.front();
                q.pop();

                // Step 3: Explore all buses passing through this stop
                for (int bus : stopToBuses[stop]) {
                    if (visitedBuses.find(bus) != visitedBuses.end())
                        continue;

                    visitedBuses.insert(bus);

                    // Step 4: Add all stops of the current bus to the queue
                    for (int nextStop : routes[bus]) {

                        if (nextStop == target)
                            return busesTaken;

                        if (visitedStops.find(nextStop) == visitedStops.end()) {
                            visitedStops.insert(nextStop);
                            q.push(nextStop);
                        }
                    }
                }
            }
        }

        return -1; // Return -1 if there is no way to reach the target
    }
};