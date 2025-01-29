class Solution {
public:
    int myAtoi(std::string s) {
        std::unordered_map<char, int> digits = {
            {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4},
            {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}
        };

        int flag = 1, i = 0, n = s.size(), answer = 0;

        while (i < n && s[i] == ' ') i++;

        if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') flag = -1;
            i++;
        }

        while (i < n && std::isdigit(s[i])) {
            int digit = digits[s[i]];

            if (answer > (INT_MAX - digit) / 10) 
                return flag == 1 ? INT_MAX : INT_MIN;

            answer = answer * 10 + digit;
            i++;
        }

        return answer * flag;
    }
};