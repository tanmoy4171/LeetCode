class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" or tokens[i]=="-" or tokens[i]=="*" or tokens[i]=="/"){
                int op2=st.top();
                st.pop();
                int op1=st.top();
                st.pop();
                switch(tokens[i][0]){
                    case '+':
                        st.push(op1+op2);
                        break;
                    case '-':
                        st.push(op1-op2);
                        break;
                    case '*':
                        st.push(op1*op2);
                        break;
                    case '/':
                        st.push(op1/op2);
                        break;
                }
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};