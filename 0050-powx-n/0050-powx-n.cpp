class Solution {
public:
    double helper(double x, long long n){
        if(n == 0){
            return 1;
        }
        if(n < 0){
            x = 1/x;
            n = -1*n;
        }

        if(n%2 == 0){
            double half = helper(x, n/2);
            return half*half;
        }else{
            return x*helper(x, n-1);
        }
    }
    double myPow(double x, int n) {
        return helper(x,n);
    }
};