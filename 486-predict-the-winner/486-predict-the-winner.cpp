class Solution {
public:
    int solve(vector<int>& nums,int i, int j ){
      if(i>j)
          return 0;
    
     int choice1=nums[i]+min(solve(nums,i+2,j),solve(nums,i+1,j-1));
     int choice2=nums[j]+min(solve(nums,i+1,j-1),solve(nums,i,j-2));
        
     return max(choice1,choice2);
        
    }
    

    bool PredictTheWinner(vector<int>& nums) {
        
        int totalSum=0;
        for(int i=0;i<nums.size();i++){
            totalSum+=nums[i];
        }
        
        int sum1= solve(nums,0,nums.size()-1);
        
        int sum2=totalSum-sum1;
        
        return sum1>=sum2;
    }
};