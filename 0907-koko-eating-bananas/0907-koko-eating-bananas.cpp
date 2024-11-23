class Solution {
public:
    int minEatingSpeed(const vector<int>& piles, const int H) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        int k = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canFinish(piles, H, mid)) {
                k = mid; // Update result and try for smaller k
                right = mid - 1;
            } else
                left = mid + 1; // Try for larger k
        }

        return k;
    }

private:
    bool canFinish(const vector<int>& piles, const int H, const int k) {
        long long hours = 0;

        for (int pile : piles)
            hours += ((pile + k - 1) / k);
              
        return hours <= H;
    }
};