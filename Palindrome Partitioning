class Solution {
public:
    bool isPalindrome(const string& s) {
        int start = 0, end = s.size() - 1;
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    void palindrome(string s, vector<string>& ans, vector<vector<string>>& list) {
        if (s.empty()) {
            list.push_back(ans);
            return;
        }

        for (int i = 1; i <= s.size(); i++) {
            string substr = s.substr(0, i);
            if (isPalindrome(substr)) {
                ans.push_back(substr);
                palindrome(s.substr(i), ans, list);
                ans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> list;
        vector<string> ans;
        palindrome(s, ans, list);
        return list;
    }
};
