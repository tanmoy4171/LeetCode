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
//Approach--->1
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return helperSumNumbers(root,0);
    }
private:
    int helperSumNumbers(TreeNode* root,int num){
        return root->left == root->right ? num * 10 + root->val :
            ((root->left ? helperSumNumbers(root->left, num * 10 + root->val) : 0) + 
            (root->right ? helperSumNumbers(root->right, num * 10 + root->val) : 0));
    }
};
//Approach-->2
// class Solution {
// public:
//     int sumNumbers(TreeNode* root) {
//         return helperSumNumbers(root,0);
//     }
// private:
//      int helperSumNumbers(TreeNode* root,int sum){
//         if(!root){
//             return 0; 
//         }
//         sum=(sum*10)+root->val; 
//         if (!root->left && !root->right){
//             return sum;
//         }  
//         return helperSumNumbers(root->left,sum)+helperSumNumbers(root->right,sum);
//     }
// };