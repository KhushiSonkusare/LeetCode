class Solution {
public:
    int helper(vector<bool>& visited, int pos, int n) {
        if (pos > n) return 1; 

        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && (i % pos == 0 || pos % i == 0)) {
                visited[i] = true;
                count += helper(visited, pos + 1, n);
                visited[i] = false;
            }
        }

        return count;
    }

    int countArrangement(int n) {
        vector<bool> visited(n + 1, false);
        return helper(visited, 1, n);
    }
};
