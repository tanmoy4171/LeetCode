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
    int maxsum(TreeNode* root,int &mx){
        if(root==NULL){
            return 0;
        }
        int leftsum=maxsum(root->left,mx);
        int rightsum=maxsum(root->right,mx);
        if(leftsum<0){
            leftsum=0;
        }
        if(rightsum<0){
            rightsum=0;
        }
        mx=max(mx,root->val+leftsum+rightsum);
        return root->val+max(leftsum,rightsum);        
    }
    int maxPathSum(TreeNode* root) {
        int mx=INT_MIN;
        maxsum(root,mx);
        return mx;
    }
};