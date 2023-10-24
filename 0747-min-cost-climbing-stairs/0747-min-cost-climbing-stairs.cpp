class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int st1 = 0, st2 = 0;
        // traverse all stairs through the loop...
        for (int idx = 0; idx < cost.size(); idx++) {
            int st0 = cost[idx] + min(st1, st2);
            // update the last two stairs value...
            st2 = st1;
            st1 = st0;
        }
        //st2 gives the cost if started climbing from index 1 and st1 from index 0...
        return  min(st2, st1);
    }
};