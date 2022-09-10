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
    vector<int>v;
    int kthSmallest(TreeNode* root, int k) {
    kthsmall(root,k);
        
        return v[k-1];
    }
    void kthsmall(TreeNode* root, int k)
    {
        if(root==NULL)
        return;
        kthsmall(root->left,k);
        v.push_back(root->val);
        if(v.size()==k)
            return;
        kthsmall(root->right,k);
        return;
    }
    
};