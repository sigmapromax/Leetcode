class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = 1e9;
        int maxprofit = 0;
        for (int price : prices) {
            maxprofit = max(maxprofit, price - minprice);
            minprice = min(minprice, price);
        }

        return maxprofit;
    }
}; 