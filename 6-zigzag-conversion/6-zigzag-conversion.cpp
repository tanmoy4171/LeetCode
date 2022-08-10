class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> result(numRows, "");
        bool increase = true;
        int i=0;
        
        if(numRows <= 1)
            return s;
        
        for( char ch: s){
            result[i] += ch;
            
            i = increase? i+1 : i-1;
            
            if((i%numRows == numRows-1) ||(i%numRows == 0)){
                increase = !increase;
            } 
        }
        
        s = "";
        for(i=0;i<numRows;i++){
            s += result[i];
        }
        
        return s;
    }
};