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
    int find(TreeNode* root){
        if(!root) return INT_MAX;
        while(root->left){
            root=root->left;
        }
        return root->val;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(root->val==key){
            if(!root->left && !root->right) return nullptr;
            else if(root->left && root->right){
                root->val=find(root->right);
                root->right=deleteNode(root->right,root->val);
            }else{
                if(root->left) return root->left;
                else return root->right;
            }
        }
        
        if(key < root->val) root->left=deleteNode(root->left,key);
        else root->right=deleteNode(root->right,key); 
        return root;
    }
};