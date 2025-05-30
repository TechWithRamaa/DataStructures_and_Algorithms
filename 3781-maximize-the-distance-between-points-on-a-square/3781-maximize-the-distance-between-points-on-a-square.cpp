class Solution {
public:
    // 2D to 1D + sort + binary search + greedy
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<long long> t(n);
        for (int i = 0; i < n; i++) {
            int x = points[i][0], y = points[i][1];
            t[i] = mapPoint(side, x, y);
        }
        sort(t.begin(), t.end());
        
        // Binary search candidate d in [0, 2*side].
        int lo = 0, hi = 2 * side, ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canPlace(t, k, side, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
    
private:
    // Map a boundary point (x,y) to a coordinate in [0, 4*side)
    long long mapPoint(int side, int x, int y) {
        // Bottom edge: (x,0) -> t = x.
        if (y == 0) return x; 
        // Right edge: (side, y) -> t = side + y.
        if (x == side) return side + y;
        // Top edge: (x, side) -> t = 3*side - x.
        if (y == side) return 3LL * side - x;
        // Left edge: (0, y) -> t = 4*side - y.
        return 4LL * side - y;
    }
    
    // Check if we can place k points along the circular perimeter (length L = 4*side)
    // with every adjacent gap at least d.
    bool canPlace(const vector<long long>& t, int k, int side, int d) {
        int n = t.size();
        long long L = 4LL * side;
        // Create an extended array: ext[i] = t[i] for i in [0, n) and ext[i+n] = t[i] + L.
        vector<long long> ext(2 * n);
        for (int i = 0; i < n; i++) {
            ext[i] = t[i];
            ext[i + n] = t[i] + L;
        }
        
        // Try every starting index in the original array.
        for (int i = 0; i < n; i++) {
            int count = 1;
            long long pos = ext[i];
            int idx = i;
            // We want to place a total of k points within the interval [ext[i], ext[i] + L)
            for (int cnt = 1; cnt < k; cnt++) {
                long long target = pos + d;
                // Use lower_bound to find the next point >= target
                auto it = std::lower_bound(ext.begin() + idx + 1, ext.begin() + i + n, target);
                if (it == ext.begin() + i + n) { // no valid point found in one circle
                    count = -1;
                    break;
                }
                idx = it - ext.begin();
                pos = ext[idx];
                count++;
            }
            // After placing k points, check the wrap–around gap.
            if (count == k && (ext[i] + L - pos) >= d)
                return true;
        }
        return false;
    }
};

class Solution0 {
public:
    // Approach1 failing for case 2
    int maxDistanceApproach1(int side, vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end());
        
        int low = 0, high = side * 2;
        int bestMaxDistance = 0;       

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(canWeGroupKPointsAtThisDistance(mid, k, points)) {
                bestMaxDistance = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return bestMaxDistance;
    }
private:    
    bool canWeGroupKPointsAtThisDistance(int d, int k, const vector<vector<int>>& points) {
        const int N = points.size();

        vector<int> pointA = points[0];
        k -= 1;

        for(int i = 1; i < N && k > 0; i++) {
            vector<int> pointB = points[i];
            int manhattanDist = getManhattanDistance(pointA, pointB);
            if(manhattanDist >= d) {
                k -= 1;
                pointA = pointB;
            }
        }

        return k <= 0;
    }

    int getManhattanDistance(const vector<int>& pointA, const vector<int>& pointB) {
        return abs(pointA[0] - pointB[0]) + abs(pointA[1] - pointB[1]);
    }
};