class Solution {
public:
    bool isSymmetric(TreeNode* root) {
    if(!root) return 1;
    queue<TreeNode*> q;
    q.push(root), q.push(root);
    while(!q.empty()) {
        TreeNode* n(q.front());
        q.pop();
        TreeNode* n2(q.front());
        q.pop();
        if(n==nullptr and n2==nullptr) continue;
        if(n==nullptr or n2==nullptr or n->val!=n2->val) return 0;
        q.push(n->left), q.push(n2->right), q.push(n->right), q.push(n2->left);
    }
    return 1;
    }
};