class Solution {
public:
    // BruteForce 
    // ~ O (n)
    int mySqrtBrute(int x) {
        int i = 0;
        while ((long long)i * i <= x) {
            i++;
        }
        return i - 1;
    }

    // Binary Search
    // ~ O ( log n )
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        
        int low = 0, high = x, ans = 0;
        while (low <= high) {
            long long mid = low + (high - low) / 2; // Use long long to prevent overflow
            long long square = mid * mid;
            
            if (square == x) {
                return mid;
            } else if (square < x) {
                ans = mid; // Store mid as the potential answer
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};