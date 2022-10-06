class TimeMap {
public:
    unordered_map<string,map<int,string>> mp;
    void set(string key, string value, int timestamp) {
        mp[key][-1*timestamp]=value;
    }
    string get(string key, int timestamp) {
        return (*mp[key].lower_bound(-1*timestamp)).second;      
    }
};