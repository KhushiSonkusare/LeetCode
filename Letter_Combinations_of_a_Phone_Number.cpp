class Solution {
public:
    void number(string digits, string ans, vector<string>& list, int n,
                vector<vector<string>>& alpha, int j) {
        if (n == 0) {
            list.push_back(ans);
            return;
        }

        for (int i = 0; i < alpha[digits[j] - '0'].size(); i++) {
            number(digits, ans + alpha[digits[j] - '0'][i], list, n - 1, alpha, j + 1);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<vector<string>> alpha = {
            {}, {}, {"a", "b", "c"}, {"d", "e", "f"}, {"g", "h", "i"},
            {"j", "k", "l"}, {"m", "n", "o"}, {"p", "q", "r", "s"},
            {"t", "u", "v"}, {"w", "x", "y", "z"}
        };

        vector<string> list;
        number(digits, "", list, digits.size(), alpha, 0);
        return list;
    }
};
