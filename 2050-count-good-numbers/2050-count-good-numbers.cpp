class Solution {
public:
    const int MOD = 1e9 + 7;

    long long expo(long long a, long long b){
        long long result = 1;
        a %= MOD;

        while (b > 0) {
            if (b % 2 == 1)
                result = (result * a) % MOD;

            a = (a * a) % MOD;
            b /= 2;
        }

        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenPositions = (n + 1) / 2;
        long long oddPositions = n / 2;

        long long ans = (expo(5, evenPositions) * expo(4, oddPositions)) % MOD;
        return (int)ans;
    }
};
