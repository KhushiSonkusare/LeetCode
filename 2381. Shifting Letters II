class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<long long> prefixSum(s.size() + 1, 0);

        for (int i = 0; i < shifts.size(); i++) {
            int add = (shifts[i][2] == 1) ? 1 : -1;
            prefixSum[shifts[i][0]] += add;
            prefixSum[shifts[i][1] + 1] -= add;
        }

        for (int i = 1; i < s.size(); i++) {
            prefixSum[i] += prefixSum[i - 1];
        }

        for (int i = 0; i < s.size(); i++) {
            int d = s[i] - 'a' + prefixSum[i];
            d = (d % 26 + 26) % 26;
            s[i] = 'a' + d;
        }

        return s;
    }
};
