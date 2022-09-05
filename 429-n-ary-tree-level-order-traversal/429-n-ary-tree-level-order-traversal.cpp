/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    vector<vector<int>>res;
public:
    vector<vector<int>> levelOrder(Node* root) {
        
		//Edge Case
        if(root==NULL){
            return res;
        }
        
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            
            int n=q.size();
            vector<int>t;
            for(int i=0; i<n; ++i){
                
                auto k=q.front();
                q.pop();
                t.push_back(k->val);
                
                for(auto &x:k->children){
                    q.push(x);
                }
                
            }
            
            res.push_back(t);
            
        }
        
        return res;
    }
};