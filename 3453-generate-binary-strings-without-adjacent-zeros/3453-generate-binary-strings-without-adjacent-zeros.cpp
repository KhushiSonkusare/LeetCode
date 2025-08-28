class Solution {
public:
    void helper(int n, string curr, vector<string> &answer, char prev) {
        if (n == 0) {
            answer.push_back(curr);
            return;
        }
        if (prev == '0') {
            helper(n - 1, curr + "1", answer, '1');
        } else {
            helper(n - 1, curr + "1", answer, '1');
            helper(n - 1, curr + "0", answer, '0');
        }
    }
    vector<string> validStrings(int n) {
        vector<string> answer;
        helper(n, "", answer, '1'); 
        return answer;
    }
};