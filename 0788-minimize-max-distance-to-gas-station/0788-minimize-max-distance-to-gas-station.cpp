class Solution {
public:
    /*
    In the context of binary search on floating-point numbers, 
    epsilon (often written as ε) is used as a precision threshold 
    — it tells the algorithm how close is “close enough”.
    */
    double minmaxGasDist(vector<int>& stations, int k) {
        double low = 0.0, high = stations.back() - stations.front();
        double epsilon = 1e-6;

        while (high - low > epsilon) {

            double mid = (low + high) / 2.0;
            
            if (isPossible(stations, k, mid))
                high = mid;
            else
                low = mid;
        }

        return low;
    }
private:
    bool isPossible(vector<int>& stations, const int k, double maxDist) {
        int needed = 0;

        for (int i = 1; i < stations.size(); i++) {
            double dist = stations[i] - stations[i - 1];
            needed += int(dist / maxDist);
        }

        return needed <= k;
    }
};