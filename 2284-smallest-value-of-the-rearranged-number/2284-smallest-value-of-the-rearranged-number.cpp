class Solution {
public:
    long long smallestNumber(long long num) {
    string ans = "";
    vector<int> v(10);
    // convert the integer to string
    string s = to_string(num);
    
    // check if the number is negative
    bool neg = false;
    if(s[0] == '-') {
        neg = true;
        s = s.substr(1, s.size()-1);
    }

    for(long long i = 0; i<s.size(); i++) {
        v[s[i]-'0']++;
    }
    
    // for negative integer
    if(neg) {
        ans = "-";
        for(int i = 9; i>=0; i--) {
            while(v[i]--) {
                ans += to_string(i);
            }
        }
    }
    
    // for positive integer
    else {
        for(int i = 1; i<10; i++) {
            if(v[i] > 0) {
                v[i]--;
                ans += to_string(i);
                break;
            }
        }
        for(int i = 0; i<10; i++) {
            while(v[i]--) {
                ans += to_string(i);
            }
        } 
    }
	return stoll(ans);
}
};