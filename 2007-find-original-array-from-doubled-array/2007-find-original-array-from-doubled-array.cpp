class Solution {
public:
    vector<int>findOriginalArray(vector<int>&changed) {
        int n = changed.size();
        vector<int>a,visited(n,0);        
		// Sorting the array is important in this approach
        sort(changed.begin(), changed.end());
		
        int i=0,j=1;
        while((i<n && j < n)){
            if(visited[i] == 1){   // Keeping a track of all elements 
                i++;
                if(i==j)
                    j++;
                continue;
            }
            if(visited[j] == 1){
                j++;
                continue;
            }
		    if(changed[j] == 2*changed[i]){
                a.push_back(changed[i]);
                visited[i]++;
                visited[j]++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        
        if(2*a.size() == changed.size())  // array obtained should be of exactly half size that of Changed array
            return a;
        return {};
    }
};