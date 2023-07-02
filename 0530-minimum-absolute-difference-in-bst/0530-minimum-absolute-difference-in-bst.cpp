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
    TreeNode* inorder(TreeNode* root)
    {
        TreeNode* temp;
        TreeNode* temp2=NULL;
        TreeNode* start=NULL;
        while(root)
        {
            
            if(root->left)
            {
                temp=root->left;
                while(temp->right)
                {
                    temp=temp->right;
                }
                temp->right=root;
                temp=root->left;
                root->left=NULL;
                root=temp;
                if(temp2)
                {
                    temp2->right=root;
                }
            }
            else
            {
                if(start==NULL)
                {
                    start=root;
                }
                temp2=root;
                root=root->right;
            }
        }
        return start;
    }
    int getMinimumDifference(TreeNode* root) {
        TreeNode* start=inorder(root);
        TreeNode* end=start->right;
        int ans=INT_MAX;
        while(end)
        {
            ans=min(ans,end->val-start->val);
            start=start->right;
            end=end->right;
        }
        return ans;    
    }
};