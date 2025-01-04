class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, pair<int, int>> charMap;

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (charMap.find(c) == charMap.end()) {
                charMap[c] = {i, i};
            } else {
                charMap[c].second = i;
            }
        }
        int count = 0;
        for (const auto& entry : charMap) { 
            if (entry.second.first != entry.second.second) { 
                set<char> str; 
                for (int i = entry.second.first + 1; i < entry.second.second; i++) {
                    str.insert(s[i]);
                }
                count += str.size();
            }
        }
        return count;
    }
};
