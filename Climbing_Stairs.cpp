class Solution {
public:
    int climbStairs(int n) {
        if (n <= 0) {
        return 1;
    } else if (n == 1) {
        return 1;
    }

    int a = 0, b = 1;
    for (int i = 2; i <= n; ++i) {
        int next = a + b;
        a = b;
        b = next;
    }

    return b+1;
    }
};