class Solution {
public:
    int binarysearch( vector<int>&arr , int prev , int index ){
        int n = arr.size() ;
        int l = index ; 
        int h = n-1; 
        while (l<=h){
            int mid = (l + h )/2 ; 
            if ( arr[mid]> prev){
                n = mid ; 
                h = mid -1 ; 
            } 
            else
                l = mid +1 ; 
        }
        return n ; 
    }
    int dp[2001][2001]; 
    int solve ( vector<int>&arr1, vector<int>&arr2, int i, int j, int prev  ){
        if ( i ==arr1.size()) return 0 ; 
        j = (upper_bound(arr2.begin()+j , arr2.end(), prev)-arr2.begin());  
        if ( dp[i][j]!=-1) return dp[i][j]; 
        if ( arr1[i]<=prev && j ==arr2.size()) return 2001; 
        int take = 2001, nottake= 2001; 
        if ( j!=arr2.size())
        take = 1+solve ( arr1, arr2, i+1 , j+1,arr2[j]);
        if(arr1[i] > prev)
        nottake = solve (arr1, arr2 , i+1 ,j , arr1[i]); 
        return  dp[i][j] = min ( take , nottake) ; 
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        memset(dp , -1, sizeof(dp));
        sort(arr2.begin() , arr2.end()); 
        int ans = solve( arr1, arr2, 0, 0, -1 ); 
        if ( ans >arr1.size() ) return -1 ; 
        return ans; 
    }
};