class Solution {
public:
    // Approach 1
    // Bruteforce -> TC ~ O ( n ^ 4 )
    vector<int> findMissingAndRepeatedValues1(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n * n;

        int repeated = -1, missing = -1;

        for (int num = 1; num <= N; num++) { // Check each number from 1 to N
            int count = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == num) {
                        count++;
                    }
                }
            }
            if (count == 2)
                repeated = num;
            if (count == 0)
                missing = num;
        }

        return {repeated, missing};
    }

    // Approach 2
    // FrequencyMap -> TC ~ O ( n ^ 2 ) 
    // SC ~ O ( n ^ 2 )
    vector<int> findMissingAndRepeatedValues2(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n * n;

        vector<int> freq(N + 1, 0);
        int repeated = -1, missing = -1;

        // Count occurrences
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                freq[grid[i][j]]++;
            }
        }

        // Identify the missing and repeated numbers
        for (int num = 1; num <= N; num++) {
            if (freq[num] == 2)
                repeated = num;
            if (freq[num] == 0)
                missing = num;
        }

        return {repeated, missing};
    }

    // Approach 3
    // Sorting -> TC ~ O ( n ^ 2 log n ^ 2 ) 
    // SC ~ O ( n ^ 2 )
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n * n;

        vector<int> arr;

        // Flatten the matrix into 1D array
        // ~ O ( n ^ 2 )
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr.push_back(grid[i][j]);
            }
        }

        // Sort the array
        sort(arr.begin(), arr.end());

        int repeated = -1, missing = -1;

        // Traverse the sorted array to find repeated and missing numbers
        for (int i = 0; i < N - 1; i++) {
            if (arr[i] == arr[i + 1]) {
                repeated = arr[i];
            } else if (arr[i + 1] - arr[i] > 1) {
                missing = arr[i] + 1;
            }
        }

        // If missing is still not found, it must be N
        if (missing == -1) {
            missing = (arr[0] != 1) ? 1 : N;
        }

        return {repeated, missing};
    }
};