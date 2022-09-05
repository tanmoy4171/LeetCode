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
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        // base case
        
        if(root == NULL)
            return {};
        
        // declare a queue
        
        queue<Node*> q;
        
        q.push(root);
        
        vector<vector<int>> res;
        
        while(!q.empty())
        {
            int size = q.size();
            
            // temp will store the nodes of one level
            
            vector<int> temp;
            
            for(int k = 0; k < size; k++)
            {
                // take out the front of the queue
                
                auto curr = q.front();
                
                q.pop();
                
                // push the curr -> val into temp
                
                temp.push_back(curr -> val);
                
                // find the childs of curr node
                
                vector<Node*> childs = curr -> children;
                
                // push all the childs of curr node into queue
                
                for(int i = 0; i < childs.size(); i++)
                {
                    q.push(childs[i]);
                }
            }
            
            // push the nodes of curr level into res
            
            res.push_back(temp);
        }
        
        return res;
    }
};