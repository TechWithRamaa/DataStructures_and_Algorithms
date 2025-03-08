class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        // Step 1: Use the Sieve of Eratosthenes to mark prime numbers
        int limit = right;
        vector<bool> isPrime(limit + 1, true);
        isPrime[0] = isPrime[1] = false;

        // upper limit, when left, right is [2, 30]
        // when i = 6, 6 * 6 becomes 36 which is breaching the upper limit
        for (int i = 2; i * i <= limit; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= limit; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Step 2: Collect primes in the range [left, right]
        vector<int> primes;
        for (int i = left; i <= right; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }

        // Step 3: Find the closest prime pair
        if (primes.size() < 2) {
            return {-1, -1}; // Not enough primes in the range
        }

        int minDiff = INT_MAX;
        vector<int> result(2, -1);

        for (int i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                result = {primes[i - 1], primes[i]};
            }
        }

        return result;
    }
};