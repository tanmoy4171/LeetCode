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
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<double> res;
        vector<int> tmp;
        int len, i;
        TreeNode *curr;
        while (q.size()) {
            tmp.clear();
            len = q.size();
            for (i = 0; i < len; i++) {
                curr = q.front();
                tmp.push_back(curr->val);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
                q.pop();
            }
            res.push_back(accumulate(begin(tmp), end(tmp), 0.0) / tmp.size());
        }
        return res;
    }
};