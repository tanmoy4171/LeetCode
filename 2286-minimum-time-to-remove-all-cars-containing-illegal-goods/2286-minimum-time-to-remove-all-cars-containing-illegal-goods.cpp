class Solution {
public:
    int minimumTime(string &s) {
        int cost = 0, total_cost = INT_MAX, n = s.length();
        for(int i = 0; i < n; i += 1){
            if(s[i] == '1'){
                total_cost = min(total_cost, cost + (n-i)); // if removed from right
                cost = min(i+1, 2+cost); // left cost = i + 1 and mid cost = 2 + cost
            }
        }
        return min(total_cost, cost); // now we have completely traversed string
    }
};