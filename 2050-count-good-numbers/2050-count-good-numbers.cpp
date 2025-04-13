class Solution {
public:
    const int MOD = 1e9 + 7;

    // Fast modular exponentiation
    long long power(long long base, long long exp) {
        long long result = 1;
        base %= MOD;

        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % MOD;

            base = (base * base) % MOD;
            exp /= 2;
        }

        return result;
    }

    int countGoodNumbers(long long n) {
        long long even_pos = (n + 1) / 2;
        long long odd_pos = n / 2;

        long long total = (power(5, even_pos) * power(4, odd_pos)) % MOD;
        return static_cast<int>(total);
    }
};
