class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL){
            return root;
        }
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<Node*>ans;
            for(int i=0; i<size; i++){
                Node* node = q.front();
                q.pop();
                if(node ->left)q.push(node ->left);
                if(node ->right)q.push(node ->right);
                ans.push_back(node);
            }
            for(int i=1; i<ans.size(); i++){
                ans[i-1] ->next = ans[i];
            }
        }
        return root;
    }
};