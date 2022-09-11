/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int result=INT_MAX;
    TreeNode*prev=NULL;
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        
        return result;
      
    }
    
    void inorder(TreeNode*root)
    {
      if(root==NULL)
          return ;
      inorder(root->left);
        if(prev!=NULL)
        {
            result=abs(prev->val-root->val)<result?abs(prev->val-root->val):result;
        }
        prev=root;
        inorder(root->right);
     }
};