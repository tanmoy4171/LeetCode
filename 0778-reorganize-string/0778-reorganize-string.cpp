
class Solution {
public:

    string reorganizeString(string s) {
        

        if(s.size() <= 1) return s;

        unordered_map<char,int>mpp;

        for(auto &it : s) mpp[it]++;
        

        if(mpp.size()==1) return "";


        priority_queue<pair<int,char>>vp;
        string res;


        for(auto &it : mpp)  vp.push({it.second,it.first});
        

          while(vp.top().first > 0)
        {
            pair<int,char> p = vp.top();
            vp.pop();

            res.push_back(p.second);
            p.first--;

            pair<int,char> p2 = vp.top();
            vp.pop();

            if(p2.first > 0)
            {
                res.push_back(p2.second);
                p2.first--;
            }

            vp.push(p);
            vp.push(p2);
        }

        for(int i=0;i<res.size()-1;++i)
        {
            if(res[i]==res[i+1]) return "";
        }

        return res;
    }
};
