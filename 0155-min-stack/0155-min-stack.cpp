class MinStack {
public:
    stack<long long> st;
    long long mn=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mn=val;
        }
        else{
            long long tempVal = val;
            if(tempVal<mn){
                tempVal=2 *tempVal*1LL - mn;
                mn=val;
            }
            st.push(tempVal);
        }
    }
    
    void pop() {
        if(st.empty()) return;
        if(st.top()<mn){
            mn=2*mn-st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.empty()) return -1;
        long long temp=st.top();
        if(temp<mn){
            return mn;
        }
        return temp;
    }
    
    int getMin() {
        return mn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */