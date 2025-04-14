class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int N = arr.size();
        int count = 0;

        for(int i = 0; i < N - 2; i++) {
            for(int j = i + 1; j < N - 1; j++) {

                if(abs(arr[j] - arr[i]) > a) // <= smart pruning here
                    continue;

                for(int k = j + 1; k < N; k++) {
                    if((abs(arr[j] - arr[k]) <= b)
                        && (abs(arr[i] - arr[k]) <= c))
                    count++;
                }
            }
        }

        return count;
    }
};