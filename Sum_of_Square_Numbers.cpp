#include <cmath>
class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i = 0;i<c ; i++){
            if(i*i + sqrt(c - (i*i)) == c)
                return true;
        }

        return false;
    }
};