class Solution {
public:
    int climbStairs(int n) {
        int first = 1, second = 2;
        if(n == 0 || n == 1 || n ==2){
            return n;
        }else{
            int next = 0;
            for(int i = 0; i<n-2; i++){
                next = first + second;
                first = second;
                second = next;
            }
            return next;
        }
    }
};