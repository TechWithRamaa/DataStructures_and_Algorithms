class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 0;
        long long high = (long long)ranks[0] * cars * cars;
        // Initial upper bound for time

        for (int r : ranks) {
            high = min(high, (long long)r * cars * cars);
            // Finding the minimum upper bound among all mechanics
        }

        long long result = high;

        // Binary search to minimize time
        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (canRepairCarsInTime(ranks, cars, mid)) {
                result = mid; // If it's possible to repair in `mid` time, try
                              // for smaller time
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }

private:
    bool canRepairCarsInTime(const vector<int>& ranks, int cars,
                             long long time) {
        long long totalCarsRepaired = 0;
        for (int r : ranks) {
            // Max cars this mechanic can repair within `time` minutes
            totalCarsRepaired += floor(sqrt(time / r));
            if (totalCarsRepaired >= cars) {
                return true;
            }
        }
        return totalCarsRepaired >= cars;
    }
    /* Why this intuition ?
    Instead of directly computing the time using \U0001d45f × \U0001d45b x n,
    we are working in reverse to determine how many cars a mechanic can repair within a given time. 
    
    This is needed because we are using binary search on time,
    checking whether a given time is sufficient to repair all cars.
    */
};