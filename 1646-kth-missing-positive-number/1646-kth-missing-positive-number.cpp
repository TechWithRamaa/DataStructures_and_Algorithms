class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int N = arr.size();

        int i = 0;
        for (int num = 1; num <= arr[N - 1] && i < N; num++) {
            cout << num << ": i - " << i << " - " << arr[i] << endl;
            if (num != arr[i]) {
                k--;
                if(k == 0) {
                    return num;
                }
            } else {
                i++;
            }
        }

        return arr[N - 1] + k;
    }
};