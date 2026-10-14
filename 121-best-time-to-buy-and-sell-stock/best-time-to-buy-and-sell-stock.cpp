class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int Profit = 0;
        for(int i=0;i<prices.size();i++){
            minPrice = min(minPrice,prices[i]);
            Profit = max(Profit,prices[i]-minPrice);
        }
        return Profit;
    }
};