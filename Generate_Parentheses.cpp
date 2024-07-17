class Solution {
public:
    void generate(int n, int openingCount, int closingCount, string ans, vector<string> *list) {
        if (openingCount == n && closingCount == n) {
            list->push_back(ans);
            return;
        }
        if (openingCount < n) {
            generate(n, openingCount + 1, closingCount, ans + "(", list);
        }
        if (closingCount < openingCount) {
            generate(n, openingCount, closingCount + 1, ans + ")", list);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> list;
        generate(n, 0, 0, "", &list);
        return list;
    }
};
