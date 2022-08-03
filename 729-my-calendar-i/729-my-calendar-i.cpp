class MyCalendar {
public:
    map<int,int> mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = mp.upper_bound(start);
        if(it!=mp.end() && (end > it->second)) return false;
        mp[end]=start;
        return true;
    }
};