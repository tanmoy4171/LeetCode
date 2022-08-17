class Solution {
public:
    int search(vector<int>& nums, int target) {
        vector<int> :: iterator it2=nums.begin();        
        vector<int> :: iterator it=std :: lower_bound(nums.begin(),nums.end(),target);        
        if(it==nums.end() || *it!=target) return -1;        
            else return (it-it2) ; 
    }
};