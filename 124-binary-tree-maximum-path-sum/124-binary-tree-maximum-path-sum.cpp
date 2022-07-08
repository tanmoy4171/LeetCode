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
    int maxi=INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        findMaxPathSum(root);
        return maxi; 
    }
private:
    int findMaxPathSum(TreeNode* root){
        if(root==0)return 0;
        int l=max(0,findMaxPathSum(root->left));
        int r=max(0,findMaxPathSum(root->right));
        maxi=max(maxi,root->val+l+r);
        return root->val +max(l,r);
    }
};

