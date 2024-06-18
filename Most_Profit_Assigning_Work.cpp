class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> store;
        for (int i = 0; i < difficulty.size(); i++) {
            store.push_back({difficulty[i], profit[i]});
        }
        sort(store.begin(), store.end());
        
        sort(worker.begin(), worker.end());

        int maxProfit = 0, totalProfit = 0, j = 0;
        for (int i = 0; i < worker.size(); i++) {
            while (j < store.size() && worker[i] >= store[j].first) {
                maxProfit = max(maxProfit, store[j].second);
                j++;
            }
            totalProfit += maxProfit;
        }
        return totalProfit;
    }
};
