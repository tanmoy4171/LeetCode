// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int arr[]) {
    vector<int>v;
    sort(arr,arr+n);
    int i=0,j=n-1,upside=0,downside=0;
    while(i<j)
    {
        v.push_back(arr[j]);
        v.push_back(arr[i]);
        upside+=arr[j];
        downside+=arr[i];
        if(upside-downside<=0)
        {
            v.clear();
            v.push_back(-1);
            return v;
        }
        j--;
        i++;
    }
    if(n%2==1)
    v.push_back(arr[i]);
    return v;
}
