class Solution {
public:
  int numFactoredBinaryTrees(vector<int>& arr) {
    int mod = 1000000007, n = arr.size();
    unsigned long long answer = 0;

    sort(arr.begin(),arr.end());
    vector<unsigned long long> dp(n);
    unordered_map<int,int> mp;
    vector<vector<tuple<int,int,int>>*> table(n, NULL);
    
    for (int i = 0; i != n; i++) mp[arr[i]] = i;

    int i = 0;
    while(true){
      if(arr[i] > 31622) break; 
      int squared = arr[i]*arr[i];
      if(mp.count(squared)){
        if(table[mp[squared]] == NULL)
          table[mp[squared]] = new vector<tuple<int,int,int>>;
        table[mp[squared]]->push_back({i,i,0});
      }
      if(squared >= arr.back()) break;
      
      int j = i + 1;
      while(true){
        unsigned long long num = (unsigned long long)(arr[i])*arr[j];
        if(num > arr.back()) break;
        if(mp.count(num)){
          if(table[mp[num]] == NULL)
            table[mp[num]] = new vector<tuple<int,int,int>>;
          table[mp[num]]->push_back({i,j,1});
        }
        j++;
      }
      i++;
    }
    
    for(int i = 0; i != n; i++){
      dp[i] = 1;
      if(table[i])
        for(int w = 0; w != table[i]->size(); w++)
          dp[i] += (dp[get<0>(table[i]->operator[](w))]*dp[get<1>(table[i]->operator[](w))]<<
                   get<2>(table[i]->operator[](w)));
    }
                
    for (unsigned long long i : dp) answer += i;
    return (int)(answer % mod);    
  }
};