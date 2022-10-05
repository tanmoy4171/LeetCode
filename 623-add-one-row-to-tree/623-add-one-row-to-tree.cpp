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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode* curr = root;
        if(depth==1){ //edge case
            TreeNode* newNode = new TreeNode(val);
            TreeNode* temp_root = root;
            root = newNode;
            root->left = temp_root;
            return root;
        }
        queue<TreeNode*> q; //to traverse using BFS
        q.push(root);
        int depth_count = 1;
        int flag = 0; //to break and return after nodes have been created and assgined
        while(flag==0 and !q.empty()){
            int len = q.size();
            depth_count++;
            for(int i=0;i<len;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(depth_count==depth){
                    TreeNode* prev_temp_left = temp->left;  //store previous left
                    TreeNode* prev_temp_right = temp->right; //store previous right
                    temp->left = new TreeNode(val);
                    if(temp->left)  //to ensure temp->left->left does not give NULL point reference error
                        temp->left->left = prev_temp_left;
                    temp->right = new TreeNode(val);
                    if(temp->right)
                        temp->right->right = prev_temp_right;
                    flag = 1; //exit condition satisified
                }
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        return root;
    }
};