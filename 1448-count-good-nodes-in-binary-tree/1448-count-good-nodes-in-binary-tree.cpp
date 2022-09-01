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
    
    void solve(TreeNode* root, int maxi, int &count){

        if(!root) return;
        if(root->val >= maxi){     //pre-order traversal
            count++;               //if root->val is greater than or equal to maxi
            maxi=root->val;        //update root->val and increment count
        }

        solve(root->left,maxi,count);
        solve(root->right,maxi,count);
    }

    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int count=0;
        solve(root,INT_MIN,count);
        return count;
    }
};