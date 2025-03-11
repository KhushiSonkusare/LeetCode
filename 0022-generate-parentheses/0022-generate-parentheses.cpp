class Solution {
public:
    void paranthesis(int open, int close, string para, vector<string>& ans) {
        if (open == 0 && close == 0) {
            ans.push_back(para);
            return;
        }
        if (open > 0) {
            paranthesis(open - 1, close, para + '(', ans);
        }
        if (close > open) {
            paranthesis(open, close - 1, para + ')', ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        paranthesis(n, n, "", ans);
        return ans;
    }
};
