class Solution {
public:
    int minEatingSpeed(const vector<int>& piles, const int H) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
    

        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(canKokoFinish(piles, H, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
private:
    bool canKokoFinish(const vector<int>& piles, const int H, int k) {
        long long h = 0;

        for(int pile : piles) {
            h += (pile + k - 1)/k;
        }

        return h <= H;
    }


};