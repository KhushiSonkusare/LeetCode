class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int max = logs[0][1];
        int maxi = 0;
        for (int i = 1; i < logs.size(); i++) {
            if (max < (logs[i][1] - logs[i - 1][1])) {
                max = logs[i][1] - logs[i - 1][1];
                maxi = logs[i][0];
            }
        }

        return maxi;
    }
};