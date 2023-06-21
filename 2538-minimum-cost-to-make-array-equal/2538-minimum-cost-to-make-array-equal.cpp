class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        long long ans=LLONG_MAX;
        vector<pair<long long,long long>> v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],cost[i]});
        }
        
        sort(v.begin(),v.end());
        vector<long long> prfx(nums.size(),0);
        vector<long long> pc(nums.size(),0);
        prfx[0]=v[0].first*v[0].second;
        pc[0]=v[0].second;
        for(int i=1;i<nums.size();i++){
            prfx[i]=prfx[i-1]+(v[i].first*v[i].second);
            pc[i]=pc[i-1]+(v[i].second);
        }
        
        for(int i=0;i<nums.size();i++){
            long long prcw=0,prc=0;
            long long ncw=0,nc=0;
            if(i>0){
                prcw=prfx[i-1];
                prc=pc[i-1];
            }
            if(i<nums.size()-1){
                ncw=prfx[nums.size()-1]-prfx[i];
                nc=pc[nums.size()-1]-pc[i];
            }
            
            prc=prc*v[i].first;
            nc=nc*v[i].first;
            
            
            long long temp=(ncw-nc)+(prc-prcw);
            ans=min(temp,ans);
        }
        
        return ans;
        
    }
};