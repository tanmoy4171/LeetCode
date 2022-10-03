class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int sumTime, maxTime;
        int ans = 0;
        
        for(int i = 0; i<n; i++){
            sumTime = neededTime[i], maxTime = neededTime[i];
            
            int j = i;
            while(j<n-1 && colors[j] == colors[j+1]){
                sumTime += neededTime[j+1];
                maxTime = max(maxTime, neededTime[j+1]);
                j++;
            }
            
            if(j != i){
                ans += (sumTime - maxTime);
                i = j-1;
            }
        }
        
        return ans;
    }
};