#include <unordered_map>
#include <vector>
#include <cmath>
#include <cctype>
#include <string>

class Solution {
public:
    int myAtoi(std::string s) {
        std::unordered_map<char, int> digits = {
            {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4},
            {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}
        };

        int flag = 1;  
        int i = 0, n = s.size();

     
        while (i < n && s[i] == ' ') i++;

        if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') flag = -1;
            i++;
        }

        std::vector<int> ans;

    
        while (i < n && std::isdigit(s[i])) {
            ans.push_back(digits[s[i]]);
            i++;
        }

        if (ans.empty()) return 0; 

        int answer = 0;

       
        for (int num : ans) {
            answer = answer * 10 + num;
        }

        return answer * flag;
    }
};
