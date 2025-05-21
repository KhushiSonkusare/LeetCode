class Solution {
    static const long long MOD = 1'000'000'007;

public:
    long long myPow(long long x, long long n, long long mod) {
        long long ans = 1;
        x %= mod;
        while (n > 0) {
            if (n % 2 != 0) {
                ans = (ans * x) % mod;
            }
            x = (x * x) % mod;
            n = n / 2;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        return (int)((myPow(5, n / 2 + n % 2, MOD) * myPow(4, n / 2, MOD)) % MOD);
    }
};