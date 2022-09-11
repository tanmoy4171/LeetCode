/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void encode(TreeNode* root, string &str){
        if(root == NULL)
            return;
        str += to_string(root->val);
        str += "-";
        encode(root->left, str);
        encode(root->right, str);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        encode(root, str);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        stringstream ss(data);
        string value;
        while(getline(ss, value, '-')){
            root = insert(root, stoi(value));
        }
        return root;
    }
    
    TreeNode* insert(TreeNode* root, int data){
        if(root == NULL){
            root = new TreeNode(data);
            return root;
        }
        if(root->val > data){
            root->left = insert(root->left, data);
            return root;
        }
        else{
            root->right = insert(root->right, data);
            return root;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;