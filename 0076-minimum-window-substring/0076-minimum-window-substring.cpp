class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mapt;
        for (char c : t) {
            mapt[c]++;
        }

        unordered_map<char, int> window;
        int have = 0, need = mapt.size();
        int left = 0;
        int minLen = INT_MAX;
        int minStart = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c]++;

            if (mapt.count(c) && window[c] == mapt[c]) {
                have++;
            }

            while (have == need) {
                if ((right - left + 1) < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }

                char leftChar = s[left];
                window[leftChar]--;
                if (mapt.count(leftChar) && window[leftChar] < mapt[leftChar]) {
                    have--;
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
