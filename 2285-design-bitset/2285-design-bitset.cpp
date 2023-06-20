class Bitset {
    
    vector<int> v;          // for storing the bits
    int n, counts, flips;  // n for the size, counts for maintaining the count of ones
                          // flips for counting the number of flips
public:
    Bitset(int size) {
        n = size;
        v = vector<int>(size,0);
        counts = flips = 0;
    }
    
    void fix(int idx) {
        if(flips%2 == 0)   // if flips is even, then the bitset will reamain as it is.
        {
            if(v[idx] == 0)
            {
                v[idx] = 1, counts++;
            }
        }
        else
        {
            if(v[idx] == 1)
            {
                v[idx] = 0, counts++;
            }
        }
    }
    
    void unfix(int idx) {
        if(flips%2 == 0)
        {
            if(v[idx] == 1)
            {
                v[idx] = 0, counts--;
            }
        }
        else
        {
            if(v[idx] == 0)
            {
                v[idx] = 1, counts--;
            }
        }
    }
    
    void flip() {
        flips += 1;
        counts = n - counts;   // changing the number of total ones
    }
    
    bool all() {
        return n == counts;
    }
    
    bool one() {
        return counts > 0;
    }
    
    int count() {
        return counts;
    }
    
    string toString() {
        string s ="";
        for(int i = 0; i < n; i++)
        {
            if(flips%2 == 0)   // if flips is even then the bitset will remain as it is.
            {
                if(v[i] == 0) s += '0';
                else  s += '1';
            }
            else
            {
                if(v[i] == 0) s += '1';
                else  s += '0';   
            }
        }
        
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */