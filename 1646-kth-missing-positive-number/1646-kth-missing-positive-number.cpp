class Solution {
public:
    // BruteForce 
    // Comparison against the actual number and the given array
    // TC ~ O ( n )
    int findKthPositive1(vector<int>& arr, int k) {
        int N = arr.size();

        int i = 0;
        for (int num = 1; num <= arr[N - 1] && i < N; num++) {
            if (num != arr[i]) {
                k--;
                if(k == 0) 
                    return num;
            } else 
                i++;
        }

        return arr[N - 1] + k;
    }

    // Binary Search [search space is array indices]
    // TC ~ O ( log N )
    int findKthPositive(vector<int>& arr, int k) {
        int N = arr.size();

        int left = 0, right = N - 1;

        while(left <= right) {
            int mid = left + ((right - left) / 2);
            int missingCount = arr[mid] - ( mid + 1 );

            if(missingCount < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left + k;
    }
};