class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size() % 2 == 1) {
            return false;
        }

        int open = 0, unlocked = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (locked[i] == '0') {
                unlocked++;
            } else if (s[i] == '(') {
                open++;
            } else {
                if (open > 0) {
                    open--;
                } else if (unlocked > 0) {
                    unlocked--;
                } else {
                    return false;
                }
            }
        }

        int close = 0;
        unlocked = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (locked[i] == '0') {
                unlocked++;
            } else if (s[i] == ')') {
                close++;
            } else {
                if (close > 0) {
                    close--;
                } else if (unlocked > 0) {
                    unlocked--;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};
