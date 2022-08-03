class MyCalendar {
public:
    
    vector<pair<int, int>> booking;
	
    MyCalendar() {
        
    }
    bool book(int start, int end) {
        for (pair<int, int> temp : booking)
        {
            if (max(temp.first, start) < min(end, temp.second))
            {
                return false;
            } 
        }
        booking.push_back({start, end});
        return true;
    }
};