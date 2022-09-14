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
    int res = 0;
    int path;
    void dfs(TreeNode *root) {
        // updating path
        path ^= 1 << root->val;
        // checking when in a leaf
        if (!root->left && !root->right) res += !(path & (path - 1));
        // exploring the branches
        if (root->left) dfs(root->left);
        if (root->right) dfs(root->right);
        // backtracking
        path ^= 1 << root->val;
    }
    int pseudoPalindromicPaths(TreeNode *root) {
        dfs(root);
        return res;
    }
};