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
    int ans=0;    
    void countPaths(TreeNode* root, int path){
        path^=(1<<root->val);
        if(!root->left && !root->right){
            if((path & (path-1))==0) ans++;
            return;
        }
        if(root->left) countPaths(root->left,path);
        if(root->right) countPaths(root->right,path);
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
      if(!root) return 0;
        countPaths(root,0);
        return ans;
    }
};