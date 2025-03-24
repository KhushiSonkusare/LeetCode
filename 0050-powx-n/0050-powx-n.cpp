class Solution {
public:
    double power(double x, long long n) {
        if (n == 0) return 1.0;
        
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }

        if (n % 2 == 0) {
            double half = power(x, n / 2);
            return half * half;
        } else {
            return x * power(x, n - 1);
        }
    }

    double myPow(double x, int n) {
        return power(x, n);
    }
};
