class Solution {
public:
    string reverseWords(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left <= right && s[left] == ' ') left++;
        while (right >= left && s[right] == ' ') right--;

        string ans = "";
        string tmp = "";

        while (left <= right) {
            char ch = s[left];
            if (ch != ' ') {
                tmp += ch;
            } else if (!tmp.empty()) {
                if (!ans.empty())
                    ans = tmp + " " + ans;
                else
                    ans = tmp;
                tmp = "";
            }
            left++;
        }

        if (!tmp.empty()) {
            if (!ans.empty())
                ans = tmp + " " + ans;
            else
                ans = tmp;
        }

        return ans;
    }
};
