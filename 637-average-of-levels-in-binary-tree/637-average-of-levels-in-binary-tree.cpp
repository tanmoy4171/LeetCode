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
    vector<double> ans;
    
    void helper(vector<TreeNode*> vect)
    {
        if(vect.size()==0)
        {
            return;
        }
        double sum=0;
        vector<TreeNode*> q;
        for(int i=0;i<vect.size();i++)
        {
            sum+=vect[i]->val;
            if(vect[i]->left)
            {
                q.push_back(vect[i]->left);
            }
            if(vect[i]->right)
            {
                q.push_back(vect[i]->right);
            }
        }
        ans.push_back(sum/vect.size());
        helper(q);
    }
    
    vector<double> averageOfLevels(TreeNode* root) 
    {
        // ans.push_back((double)root->val);
        vector<TreeNode*> vect;
        vect.push_back(root);
        helper(vect);
        return ans;
    }
};