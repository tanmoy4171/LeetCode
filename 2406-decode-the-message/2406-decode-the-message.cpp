class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<bool> flag(26,false);
        char map[26];
        int curAlp=97;

        //creating a map for key where value is stored as follows
        // map[alphabet] contains value it maps
        for(int i=0;i<key.length();i++){
            if(key[i] != ' '){
                // checking if value already exists
                if(flag[key[i]-97] == false){
                    map[key[i]-97] = (char)curAlp;
                    flag[key[i]-97] = true;
                    curAlp++;
                }
            }
        }

        // creating decoded string
        string ans="";
        for(int j=0;j<message.length();j++){
            if(message[j] == ' '){
                ans += " ";
            }else{
                // map[alphabet] returns decoded char
                ans += map[message[j]-97];
            }
        }

        return ans;
    }
};