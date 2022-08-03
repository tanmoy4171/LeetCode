class Node{
    public:
    int startDate,endDate;
    Node*left;
    Node*right;
    Node(int startDate,int endDate){
        this->startDate=startDate;
        this->endDate=endDate;
        this->left=NULL;
        this->right=NULL;
    }
};
class MyCalendar {
private:
    Node*root;
    bool _book(Node*node,int start,int end){
        if(!node){
            return true;
        } else if(node->endDate<=start){
            if(!node->right){
                return true;
            } else {
                return this->_book(node->right,start,end);
            }
        } else if(node->startDate>=end){
            if(!node->left){
                return true;
            } else {
                return this->_book(node->left,start,end);
            }
        } else {
            return false;
        }
    }
    Node*_update(Node*node,int start,int end){
        if(!node){
            node=new Node(start,end);
            return node;
        } else {
            if(node->endDate<=start){
                node->right=this->_update(node->right,start,end);
            } else {
                node->left=this->_update(node->left,start,end);
            }
            return node;
        }
    }
public:
    MyCalendar() {
        this->root=NULL;
    }
    
    bool book(int start, int end) {
        bool ans=this->_book(this->root,start,end);
        if(ans){
            this->root=this->_update(this->root,start,end);
        }
        return ans;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */