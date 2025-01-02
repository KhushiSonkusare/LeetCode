class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefixSum(words.size(), 0);
        vector<int> qlist(queries.size(), 0);


        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            int count = (isVowel(word[0]) && isVowel(word[word.size() - 1])) ? 1 : 0;
            prefixSum[i] = (i == 0) ? count : prefixSum[i - 1] + count;
        }

        for (int i = 0; i < queries.size(); i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            qlist[i] = (start == 0) ? prefixSum[end] : prefixSum[end] - prefixSum[start - 1];
        }

        return qlist;
    }
};
