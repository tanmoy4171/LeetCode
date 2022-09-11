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
    unordered_map<int, int> f;
    void dfs(TreeNode* root) {
        if (!root) return;
        else f[root->val]++;
        dfs(root->left);
        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int tMax = -1;
        dfs(root);
        for (auto e: f) {
            if (e.second == tMax) res.push_back(e.first);
            else if (e.second > tMax) {
                tMax = e.second;
                res = {e.first};
            }
        }
        return res;
    }
};