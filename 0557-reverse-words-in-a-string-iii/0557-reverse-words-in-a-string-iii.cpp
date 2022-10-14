class Solution {
public:
    void help(string &s,int i, int j){
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
    string reverseWords(string s) {
        int n = s.length();
        int i = 0, j = 0;
        while(j<n){
            if(s[j] != ' ') j++;
            else{
                help(s,i,j-1);
                j++;
                i = j;
            }
        }
        help(s,i,j-1);
        return s;
    }
};