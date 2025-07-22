class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freq;

            for (int j = i; j < n; j++) {
                freq[s[j]]++;

                int maxFreq = INT_MIN;
                int minFreq = INT_MAX;

                for (auto &p : freq) {
                    maxFreq = max(maxFreq, p.second);
                    minFreq = min(minFreq, p.second);
                }

                ans += (maxFreq - minFreq);
            }
        }

        return ans;
    }
};
