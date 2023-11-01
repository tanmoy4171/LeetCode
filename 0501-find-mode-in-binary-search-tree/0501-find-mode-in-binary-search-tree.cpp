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
        void recur(TreeNode* root, vector<int>& res, int& val, int& count, int& maxCount) {
        if (!root) return;
        recur(root->left, res, val, count, maxCount);
        if (root->val == val) {
            count++;
        } else {
            if (count > maxCount) {
                res.clear();
                res.push_back(val);
                maxCount = count;
            } else if ((count != 0) && (count == maxCount)) {
                res.push_back(val);
            }
            count = 1;
            val = root->val;
        }
        recur(root->right, res, val, count, maxCount);
        return;
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int val = INT_MIN, count = 0, maxCount = 0;
        recur(root, res, val, count, maxCount);
        if (count > maxCount) {
            res.clear();
            res.push_back(val);
        } else if ((count != 0) && (count == maxCount)) {
            res.push_back(val);
        }
        return res;
    }
};