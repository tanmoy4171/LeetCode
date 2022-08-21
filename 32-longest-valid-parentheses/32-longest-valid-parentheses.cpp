class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>stck;
        stck.push(-1);
        int res=0;
        
        for(int i=0;i<s.size();i++){
            
            if(s[i]=='(') stck.push(i);
            
            else{
                if(!stck.empty())stck.pop();
                
                if(!stck.empty()){
                    res=max(res,i-stck.top());
                }
                else stck.push(i);
            }
        }
        
        return res;
    }
};