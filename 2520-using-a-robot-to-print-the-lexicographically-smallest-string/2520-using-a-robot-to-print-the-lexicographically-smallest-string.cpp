class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();
        vector<char> minSuffix(n); // Fill minSuffix array
        minSuffix[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            minSuffix[i] = min(s[i], minSuffix[i + 1]);
        }

        stack<char> t;
        string result;
        int i = 0;

        while (i < n || !t.empty()) {
            while (i < n && (t.empty() || t.top() > minSuffix[i])) {
                t.push(s[i]);
                i++;
            }

            result += t.top();
            t.pop();
        }

        return result;
    }
};
