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
	TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL )
            return root;
        
        auto p=pruneTree(root->left);// check for left subtree
        auto q=pruneTree(root->right);// check for right subtree
        
        if(p==NULL)// if left subtree is not containing 1, remove it
            root->left=NULL;
        if(q==NULL)// if left subtree is not containing 1, remove it
            root->right=NULL;
        
        // if any of left or right or the root is having 1, then return 1
        // by return 1, we mean that this subtree should not get removed.
        if(p || q || root->val)
            return root;
        return NULL;
    }
};