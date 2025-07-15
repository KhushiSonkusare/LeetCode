#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAlphaNumeric(const string &word) {
        for (char c : word) {
            if (!isalnum(c)) return false; 
        }
        return true;
    }

    bool isValid(string word) {
        if (word.size() < 3 || !isAlphaNumeric(word)) {
            return false;
        }

        string vowels = "aeiouAEIOU"; 
        bool hasCons = false, hasVow = false;

        for (char c : word) {
            if (isalpha(c)) { 
                if (vowels.find(c) != string::npos) {
                    hasVow = true;
                } else {
                    hasCons = true;
                }
            }
        }

        return hasCons && hasVow;
    }
};
