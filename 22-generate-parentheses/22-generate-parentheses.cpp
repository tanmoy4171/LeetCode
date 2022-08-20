class Solution {
public:
    vector<string> res;
    
    void solve(string asf,int open,int close){
        
        if(open == 0 && close == 0){
            res.push_back(asf);
            return;
        }
       
	   // for open braces, there is always  a choice
        if(open != 0){
              solve(asf + '(',open - 1,close);
        }
        
		// close braces should be higher than open, otherwise it leads to not balanced paranthesis.                 // Example : ()) can't be balanced
        if(close>open){
            solve(asf + ')',open,close - 1);
        }
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        int open = n,close = n;
        string asf = "";
        
        solve(asf,open,close);
        return res;
        
    }
};