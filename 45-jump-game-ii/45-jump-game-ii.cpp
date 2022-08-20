class Solution {
public:
    int jump(vector<int>& nums) {
        
        int numOfJumps = 0, currentIntervalEnd = 0, farthestReachFoundSoFar = 0;
        
        for(int i = 0 ; i < nums.size() - 1 ; i++) {     // Because you can stop the work once youve
                                                                            // reached the last index
            farthestReachFoundSoFar = max(farthestReachFoundSoFar, i + nums[i]);    // maximize our                                                                                                    
                                                                                    // reach
            if(i == currentIntervalEnd) {                // When we reach the end of current intervals
                                                         // end, we need to make our next jump and
                numOfJumps++;                            // and update our current interval end with       
                currentIntervalEnd = farthestReachFoundSoFar;   // the farthest reach found so far
                                                         // We made sure this was the best possible jump
            }                                            // because we traversed th whole interval and 
        }                                                // maximized our reach and now we are sure
        return numOfJumps;                               // where our next jump will be. Greedy!
    }
};