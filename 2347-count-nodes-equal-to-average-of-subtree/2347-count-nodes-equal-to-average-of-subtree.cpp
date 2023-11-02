class Solution {
public:
    int cnt = 0;
    pair<int,int> solve(TreeNode* root)
    {
        if(root == NULL)
            return {0,0};
        auto left = solve(root->left);
        auto right = solve(root->right);
        int sum = left.first + right.first + root->val;
        int nodes = left.second + right.second + 1;
        if(sum/nodes == root->val)
            cnt++;
        return {sum,nodes};
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return cnt;
    }
};