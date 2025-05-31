class Solution {
public:
    bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int days) {
        int bouquets = 0, flowers = 0;

        for (int day : bloomDay) {
            if (day <= days) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0; // reset if bloom not ready
            }
        }
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalFlowersNeeded = 1LL * m * k;
        if (bloomDay.size() < totalFlowersNeeded)
            return -1;

        int low = 1, high = *max_element(bloomDay.begin(), bloomDay.end());
        int answer = -1;

        while (low < high) {
            int mid = (low + high) / 2;

            if (canMakeBouquets(bloomDay, m, k, mid)) {
                high = mid;
            } else {
                low = mid + 1; // need to wait more days
            }
        }

        return low;
    }
};