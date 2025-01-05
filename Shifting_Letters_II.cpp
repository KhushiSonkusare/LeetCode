class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> prefixSum(s.size(), 0);

        for (int i = 0; i < shifts.size(); i++) {
            int add = -1;
            if (shifts[i][2] == 1) {
                add = 1;
            }
            for (int k = shifts[i][0]; k <= shifts[i][1]; k++) {
                prefixSum[k] += add;
            }
        }

        for (int i = 0; i < s.size(); i++) {
            s[i] = (s[i] - 'a' + prefixSum[i] + 26) % 26 + 'a';  
        }

        return s;
    }
};
