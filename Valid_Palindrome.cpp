class Solution {
public:
    bool check(const string& s, int left, int right) {
        if (left >= right) 
            return true; // Base case: Pointers have crossed or are at the same position

        if (s[left] != s[right]) 
            return false; // Mismatch found

        return check(s, left + 1, right - 1); // Recursive call for the next pair
    }

    bool isPalindrome(string s) {
        // Step 1: Preprocess the string (lowercase and remove non-alphanumeric characters)
        string modifiedString = "";
        for (char c : s) {
            if (isalnum(c)) {
                modifiedString += tolower(c);
            }
        }

        // Step 2: Use recursion to check if the string is a palindrome
        return check(modifiedString, 0, modifiedString.size() - 1);
    }
};
