class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        vector<vector<int>> resV;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto it:a){
            pq.push({it+b[0],0});
        }
        while(k-- && !pq.empty()){
            int sum=pq.top().first;
            int pos=pq.top().second;
            resV.push_back({sum-b[pos],b[pos]});
            pq.pop();
            if(pos+1<b.size()){
                pq.push({sum-b[pos]+b[pos+1],pos+1});
            }
        }
        return resV;
    }
};