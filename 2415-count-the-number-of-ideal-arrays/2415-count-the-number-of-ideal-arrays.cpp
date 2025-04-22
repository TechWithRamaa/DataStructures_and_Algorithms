class Solution1 {
public:
    int idealArrays(int n, int maxValue) {
        const int MOD = 1e9 + 7;

        // dp[i][x] will store the number of valid arrays of length i + 1, ending with value x
        vector<vector<long long>> dp(n, vector<long long>(maxValue + 1, 0));

        // Base case: all values from 1 to maxValue are valid for the first element
        for (int x = 1; x <= maxValue; ++x) {
            dp[0][x] = 1;
        }

        // DP transition: for each index i and possible value x for arr[i], 
        // find all y that arr[i-1] (y) divides arr[i] (x)
        for (int i = 1; i < n; ++i) {
            for (int x = 1; x <= maxValue; ++x) {
                for (int y = 1; y <= maxValue; ++y) {
                    if (x % y == 0) {  // x must be divisible by y
                        dp[i][x] = (dp[i][x] + dp[i - 1][y]) % MOD;
                    }
                }
            }
        }

        // Sum all valid arrays of length n
        long long result = 0;
        for (int x = 1; x <= maxValue; ++x) {
            result = (result + dp[n - 1][x]) % MOD;
        }

        return result;
    }
};

const int MOD = 1e9 + 7, MAX_N = 1e4 + 10,
          MAX_P = 15;  // There are up to 15 prime factors
int c[MAX_N + MAX_P][MAX_P + 1];
vector<int> ps[MAX_N];  // List of prime factor counts
int sieve[MAX_N];       // Minimum prime factor

class Solution {
public:
    Solution() {
        if (c[0][0]) {
            return;
        }
        for (int i = 2; i < MAX_N; i++) {
            if (sieve[i] == 0) {
                for (int j = i; j < MAX_N; j += i) {
                    sieve[j] = i;
                }
            }
        }
        for (int i = 2; i < MAX_N; i++) {
            int x = i;
            while (x > 1) {
                int p = sieve[x];
                int cnt = 0;
                while (x % p == 0) {
                    x /= p;
                    cnt++;
                }
                ps[i].push_back(cnt);
            }
        }
        c[0][0] = 1;
        for (int i = 1; i < MAX_N + MAX_P; i++) {
            c[i][0] = 1;
            for (int j = 1; j <= min(i, MAX_P); j++) {
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
            }
        }
    }
    int idealArrays(int n, int maxValue) {
        long long ans = 0;
        for (int x = 1; x <= maxValue; x++) {
            long long mul = 1;
            for (int p : ps[x]) {
                mul = mul * c[n + p - 1][p] % MOD;
            }
            ans = (ans + mul) % MOD;
        }
        return ans;
    }
};
