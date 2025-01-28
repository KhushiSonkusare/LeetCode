class Solution {
public:
    bool check(string s, long long left, long long right){
        
         if (left >= right) 
            return true;

        if (s[left] == s[right]) 
            return check(s, left + 1, right - 1); 
        
        return false;
    }
    bool isPalindrome(string s) {
        string modifiedString = "";

        for (char c : s) {
            if (isalnum(c)) {
                modifiedString += tolower(c);
            }
        }
        return check(modifiedString, 0, modifiedString.size()-1);

    }
};