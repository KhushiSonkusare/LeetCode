class Solution {
public:
    string makeSmallestPalindrome(string s) {
       for(int i = 0; i < s.size() / 2; i++) {
            if(s[i] != s[s.size() - i - 1]) {
                if(s[i] > s[s.size() - i - 1])
                    s[i] = s[s.size() - i - 1];
                else
                    s[s.size() - i - 1] = s[i];
            }
        }
        return s;
    }
};