class Solution {
public:
    struct Node{
        Node *link[26];
        bool flag = false;
    };

    Node *root;
    
    void insert(string &word) {
        Node *trav = root;
        for(int i=0; i<word.size(); i++){
            if(trav->link[word[i]-'a'] == NULL){
                trav->link[word[i]-'a'] = new Node();
            }
            trav = trav->link[word[i]-'a'];
        }
        trav->flag = true;
    }

    void getRoot(string &word, string &item){
        Node *trav = root;
        for(int i=0; i<word.size(); i++){
            if(trav->link[word[i]-'a'] != NULL){
                item.push_back(word[i]);
                trav = trav->link[word[i]-'a'];
            }
            else break;
            if(trav->flag == true) return;
        }
        item = word;
    }

    string replaceWords(vector<string>& dict, string &sent) {
        root = new Node();
        string s;
        string str;
        for(int i=0;  i<dict.size(); i++){
            insert(dict[i]);
        }
        stringstream ss(sent); 
        while (getline(ss, str, ' ')){
            string item = "";
            getRoot(str, item);
            s += (item + " ");
        } 
        s.pop_back();
        return s;
    }
};