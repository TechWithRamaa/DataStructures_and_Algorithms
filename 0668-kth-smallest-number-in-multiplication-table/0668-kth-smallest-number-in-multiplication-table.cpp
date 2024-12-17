class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int low = 1, high = m * n; 

        while (low < high) {
            int mid = low + (high - low) / 2; 
            int count = countLessEqual(mid, m, n);

            if (count < k) 
                low = mid + 1; 
            else 
                high = mid; 
        }
        
        return low;  
    }
private:
    int countLessEqual(int target, int m, int n) {
        int count = 0;
        for (int i = 1; i <= m; ++i) 
            count += min(target / i, n); 
        
        return count;
    }
};