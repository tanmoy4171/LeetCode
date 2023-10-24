
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        
       vector<int>level;

       if(root == NULL) return level;
       queue<TreeNode*>q;
       q.push(root);

       while(!q.empty())
       {
           
           int n = q.size();
           int maxi = INT_MIN;
           
           for(int i = 0;i<n;++i)
           {
               auto temp = q.front();
               int val = temp->val;
               q.pop();
               

               if(temp->left!=NULL) q.push(temp->left);
               if(temp->right!=NULL) q.push(temp->right);
            
               maxi = max(maxi,val);
           }

            level.push_back(maxi);
        
       }

       return level; 
    }
};