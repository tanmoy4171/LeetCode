// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        long long int num1=0,num2=0;
       sort(arr,arr+n);int n1=0,n2=0,count=0;
       for(int i=0;i<n;i++){
           if(count==0){
               num1=(num1*10)+arr[i];
               count=1;n1++;
               continue;
           }
           num2=(num2*10)+arr[i];
           count=0;n2++;
       }
       return (num1+num2);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends