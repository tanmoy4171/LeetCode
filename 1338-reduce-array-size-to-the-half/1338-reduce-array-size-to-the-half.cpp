class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int freq[100001];
        for(int i = 0 ; i < 100001 ; i++)
            freq[i] = 0;
            
        int n = arr.size();
        for(int i = 0 ; i < n ; i++)
        {
            freq[arr[i]]++;
        }
        sort(freq , freq+100001);
        int sum = 0;
        int cnt = 0;
        for(int i = 100000 ; i >= 0 ; i--)
        {
            if(freq[i] != 0){
                sum+=freq[i];
                cnt++;
            }
            if(sum >= n/2)
                return cnt;
        }
        
        return 0;
    }
};