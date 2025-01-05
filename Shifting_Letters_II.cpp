class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<long long> prefixSum(s.size(), 0);

        // Calculate prefix sum of shifts
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
            int d = s[i] - 'a' + prefixSum[i];
            d = (d % 26 + 26) % 26; 
            s[i] = 'a' + d;
        }

        return s;
    }
};
