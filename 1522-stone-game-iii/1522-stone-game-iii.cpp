class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int a=0,b=0,c=0;
        for(int i=stoneValue.size()-1;i>=0;i--){
            int sum=stoneValue[i];
            int curr_a=sum-c,curr_b=sum+a,curr_c=sum+b;
            curr_c=max(curr_a,max(curr_b,curr_c));
            a=curr_a;
            b=curr_b;
            c=curr_c;
        }        
        return (c>0)?"Alice":((c==0)?"Tie":"Bob");
    }
};