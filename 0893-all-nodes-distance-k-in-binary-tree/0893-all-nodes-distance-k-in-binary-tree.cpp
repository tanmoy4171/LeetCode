/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int>ans;
    void bfs(vector<vector<int>>&adj, int curr, int parent, int k)
    {
        if(k==0)
        {
            ans.push_back(curr);
            return;
        }
        for(auto x:adj[curr])
        {
            if(x!=parent)
            bfs(adj, x, curr, k-1);
        }
    }
    void fill(vector<vector<int>>&adj, TreeNode * root)
    {
        if(root==NULL)
        return;
        else
        {
            if(root->left!=NULL)
            {
                adj[root->val].push_back(root->left->val);
                adj[root->left->val].push_back(root->val);
                fill(adj, root->left);
            }
            if(root->right!=NULL)
            {
                adj[root->val].push_back(root->right->val);
                adj[root->right->val].push_back(root->val);
                fill(adj, root->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<vector<int>>adj(500);
        fill(adj, root);
        bfs(adj, target->val, -1,k);
        return ans;
    }
};