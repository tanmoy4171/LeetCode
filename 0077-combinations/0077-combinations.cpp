class Solution {
    int K,N;
    void helper(vector<vector<int>> &ans, vector<int> &curr, int pos, int val){
        if(curr.size()==K){
            ans.push_back(curr);
            return;
        }
        if((K-pos)>(N-val+1)) return;
        
        for(int i=val; i<=N; ++i){
            curr.push_back(i);
            helper(ans,curr,pos+1,i+1);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        K=k, N=n;
        vector<vector<int>> ans;
        vector<int> curr;
        helper(ans,curr,0,1);
        return ans;
    }
};