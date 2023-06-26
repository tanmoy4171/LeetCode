class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        int n=arr.size();
        map<int,int>freq;
        for(int i:arr){
            freq[i]++;
        }
        map<int,vector<int>>Reversefreq;
        for(auto it:freq){
            Reversefreq[it.second].push_back(it.first);
        }
        vector<int> ans;
        for(int f=n;f>=0;f--){
            if(k==0)break;
            for(int num:Reversefreq[f]){
                ans.push_back(num);
                k--;
                if(k==0)break;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};