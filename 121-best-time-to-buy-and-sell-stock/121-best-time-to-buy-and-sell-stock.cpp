class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int minvalue = INT_MAX;
        for(int i =0;i<prices.size();i++){
            minvalue = min(prices[i],minvalue);
            maxprofit= max(maxprofit,prices[i] - minvalue);
        }
        return maxprofit;
    }
};