class Solution {
public:
    double power(double x, int n) {
        if (n == 0) return 1.0;
        if(x == 1) return 1.0;
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        double half = power(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return x * half * half;
        }
    }

    double myPow(double x, int n) {
        return power(x, n);
    }
};
