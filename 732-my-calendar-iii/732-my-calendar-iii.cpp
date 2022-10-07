class MyCalendarThree {
    private:
    map<int, int>m1;
    int ans;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        m1[start]++;
        m1[end]--;
        int sum = 0;
        for(auto [_,x]:m1){
            sum+=x;
            ans = max(ans, sum);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */