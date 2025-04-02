class Solution {
public:
    // BruteForce 
    // Comparison against the actual number and the given array
    // TC ~ O ( n )
    int findKthPositive(vector<int>& arr, int k) {
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
};