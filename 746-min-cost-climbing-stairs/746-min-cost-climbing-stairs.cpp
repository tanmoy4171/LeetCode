class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int curr1 = cost[0]; // minimum cost of reaching till 0th index 
        int curr2 = cost[1]; // minimum cost of reaching till 1st index 
        for(int i=2; i<n; i++){
            int temp = min(curr1, curr2) + cost[i];
            curr1 = curr2; // minimum cost of reaching till i-1th index 
            curr2 = temp; // minimum cost of reaching till i-2th index
        }
        return min(curr1, curr2); // minimum of the costs of reaching the last or second last index
    }
};