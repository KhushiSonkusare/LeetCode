class Solution {
public:
    bool isPalindrome(const string &s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }

    void helper(vector<vector<string>> &ans, vector<string> &curr, int ind, const string &s) {
        if (ind == s.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = ind; i < s.size(); i++) {
            if (isPalindrome(s, ind, i)) {
                curr.push_back(s.substr(ind, i - ind + 1)); 
                helper(ans, curr, i + 1, s);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        helper(ans, curr, 0, s);
        return ans;
    }
};
