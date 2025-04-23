class Solution {
public:
    int sumOfDigits(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10; 
            n /= 10;       
        }
        return sum;
    }

    int countLargestGroup(int n) {
        unordered_map<int, int> map;
        int max = 0, size = 0;

        for (int i = 1; i <= n; i++) {
            int sum = sumOfDigits(i);
            map[sum]++;

            if (map[sum] > size) {
                size = map[sum];
                max = 1;
            } else if (map[sum] == size) {
                max++;
            }
        }

        return max;
    }
};
