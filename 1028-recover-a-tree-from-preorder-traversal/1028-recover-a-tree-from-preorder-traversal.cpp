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
    TreeNode* recoverFromPreorder(string traversal) {
        vector <TreeNode*> st;                       //Stack Declaration
        for(int i=0; i<traversal.size(); ){
            int level=0, val=0;                      //Variables for level and number
            while(traversal[i] == '-')
                level++, i++;                        //Calculating Level
            while(i < traversal.size() && traversal[i] != '-'){      //Storing number in val
                val*=10;
                val+=traversal[i]-'0';                       //Converting char to int
                i++;
            }
            TreeNode* node = new TreeNode(val);                   //Creating new node
            while(st.size()>level) st.pop_back();                 //Finding right level to Insert
            if(!st.empty()){
                if(!st.back()->left) st.back()->left=node;        //Checking left child first
                else st.back()->right=node;                       //Creating right child if left child already present
            }
            st.push_back(node);                                   //Pushing new node to stack
        }
        return st[0];                                             //Returning head
    }
};