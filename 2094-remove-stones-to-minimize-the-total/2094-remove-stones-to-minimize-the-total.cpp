class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int arr[10001]={0};
        for(auto &it :piles){
            arr[it]++;
        }
        int s=0;
        for(int i=10000;i>0;i--){
            while(arr[i]-->0){
                if(k-->0){
                int p=i-(int)floor(i/2);
                arr[p]++;
                }
                else
                s+=i;
            }
        }
return s;
    }
};
// const minStoneSum = ( piles, k ) => {
//     let c = Array(10001).fill(0), s = 0
//     piles.forEach( i => c[i]++ )
//     for ( let i = c.length-1; i > 0; i-- )
//         while ( c[i]-- > 0 )
//             k-- > 0 ? c[Math.ceil(i/2)]++ : s += i
//     return s
// }