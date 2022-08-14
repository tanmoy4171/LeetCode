class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro=0,mn=INT_MAX;
        
        for(int i=0;i<prices.size();i++)
        { 
            mn=min(mn,prices[i]);
            maxPro=max(maxPro,prices[i]-mn);
         
        }
        return maxPro;
    }
};