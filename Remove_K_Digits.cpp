class Solution {
public:
    string removeKdigits(string num, int k) {

        if (k >= num.size()) return "0";

        int i = 0;
        while (k > 0) {
            i = (i > 0) ? (i - 1) : 0;

            while (i < num.size() - 1 && num[i] <= num[i + 1]) {
                i++;
            }
            num.erase(i, 1);
            k--;
        }

        i = 0;
        while (i < num.size() - 1 && num[i] == '0') {
            num.erase(i, 1);
        }

        if (num.empty()) {
            num = "0";
        }

        return num;
    }
};
