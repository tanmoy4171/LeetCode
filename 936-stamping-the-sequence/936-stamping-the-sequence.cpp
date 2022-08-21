// build prefix maximum match length table for KMP algorithm
vector<int> buildPMT(string s){
    int n = s.length();
    int j = 0;
    vector<int> pmt(n, 0);
    for(int i = 1; i < n; ++i){
        while(j > 0 && s[i] != s[j]){ j = pmt[j-1]; }
        if(s[i] == s[j]){ pmt[i] = ++j; }
    }
    return pmt;
}

class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        s = stamp;
        t = target;
        slen = s.length();
        tlen = t.length();
        pmt = buildPMT(s);
        ans.clear();
        
        bool success = divideConquer(0, tlen);
        if(!success) return {};
        reverse(ans.begin(), ans.end());
        return ans;
    }
private:
    bool divideConquer(int start, int end) {
        if(start >= end) { return true; }
        
        // can find complete match
        int idx = kmpFind(start, end);
        if(idx >= 0){
            ans.push_back(idx);
            return divideConquer(start, idx) && divideConquer(idx+slen, end);
        }
        
        // cannot find complete match, so need to find partial match
        while(start < end){
            idx = bfFind(start, end);
            if(idx < 0) { return false; }
            ans.push_back(idx);
            
            // partial match is at the beginning
            if(idx < start) { start = idx + slen; }
            // partial match is at the end
            else { end = idx; }
        }
        
        return true;
    }
    
    // kmp search to find complete match in the middle
    // returns the beginning of the first match found; or -1 if no match is found
    int kmpFind(int start, int end) {
        for(int i=start, j=0; i<end; ++i){
            while(j > 0 && t[i] != s[j]){ j = pmt[j-1]; }
            if(t[i] == s[j] && ++j == slen){ return i + 1 - slen; }
        }
        return -1;
    }
    
    // brute force search to find partial match at the beginning or end
    // returns the beginning of the first match found; or -1 if no match is found
    int bfFind(int start, int end) {
        int firstwin, lastwin;
        int i, j;
        
        // search for partial match at the beginning
        // stamp:  xxxabc...
        // target: ***abc...
        //            ^
        //          start
        // * means no need to consider, because the position will be stamped later
        firstwin = max(start+1-slen, 0);
        lastwin = min(start-1, tlen-slen);
        for(int winstart = lastwin; winstart >= firstwin; --winstart){
            for(j=start-winstart, i=start; 
                j<slen && (i>=end || t[i]==s[j]); 
                ++j, ++i);
            if(j == slen){ return winstart; }
        }
        
        // search for partial match at the end
        // stamp:  ...abcxxx
        // target: ...abc***
        //              ^
        //            end-1
        // * means no need to consider, because the position will be stamped later
        firstwin = max(end-slen, 0);
        lastwin = min(end-1, tlen-slen);
        for(int winstart = firstwin; winstart <= lastwin; ++winstart){
            for(j=0, i=winstart; 
                i<end && (i<start || t[i]==s[j]); 
                ++j, ++i);
            if(i == end){ return winstart; }
        }
        
        return -1;
    }
    
    string s;
    string t;
    int slen;
    int tlen;
    vector<int> pmt;
    vector<int> ans;
};