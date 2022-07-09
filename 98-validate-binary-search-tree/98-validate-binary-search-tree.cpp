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
    bool solve(TreeNode* root,long long int min,long long int max){
        if(!root){
            return true;
        }
        if(root->val>=max || root->val<=min){
            return false;
        }
        return solve(root->left,min,root->val) and solve(root->right,root->val,max); 
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,-1e18,1e18);
    }
};