class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        int n = paths.size();
        // Hashmap to store all file paths for each unique data
        unordered_map<string,vector<string>> datafiles; 
        vector<vector<string>> ans;
        
        for(string path : paths){  
            string dir="";
            string splitpath="";
            string data="";
            
            for(int i=0;i<path.length();i++){
                if(path[i]=='('){  // Extract data from path
                    i++;
                    while(path[i]!=')'){
                        data+=path[i];
                        i++;
                    }
                    datafiles[data].push_back(dir+'/'+splitpath);
                    data="";
                    
                }else if(path[i]==' '){ // Extract filename or dirname from path
                    if(dir==""){
                        dir=splitpath;
                    }
                    splitpath="";
                }else{
                    splitpath+=path[i];
                }
            }
        }
        // Add all duplicate files(lenght>1) to ans
        for(auto files : datafiles){
            if(files.second.size()>1){
                ans.push_back(files.second);
            }
        }
        return ans;

    }
};