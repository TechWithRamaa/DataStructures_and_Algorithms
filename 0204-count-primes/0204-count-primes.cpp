class Solution {
public:
    int countPrimes(int n) {
        int noOfPrimes = 0;

        vector<bool> isPrime(n + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for (int i = 2; i * i < n; i++) {
            if (isPrime[i])
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
        }

        for (int i = 0; i < n; i++) {
            if (isPrime[i]) {
                noOfPrimes += 1;
            }
        }

        return noOfPrimes;
    }
};