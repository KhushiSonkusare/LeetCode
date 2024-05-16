class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());

        if(size(prices)>1){
            if(prices[0] + prices[1] <= 3){
                return (3 - prices[0] - prices[1]);
            }
        }
        return 3;
        
    }
};