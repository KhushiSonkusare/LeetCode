class Solution {
public:
    double power(double x, int n) {
        if (n == 0) {
            return 1;
        }

        return x * power(x, n - 1);  
    }

    double myPow(double x, int n) {
        if (n > 0) {
            return power(x, n);
        } else if (n == 0) {
            return 1;  
        } else if (x == 0) {
            return 0;  
        } else {
            return 1 / power(x, -n);  
        }
    }
};
