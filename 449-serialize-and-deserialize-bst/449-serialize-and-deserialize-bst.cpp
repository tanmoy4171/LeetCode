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
    // encoding logic
    string serialize(TreeNode* root) {
        // edge case out
        if (!root) return "";
        // support variables
        string res = to_string(root->val);
        int len = 1;
        queue<TreeNode*> q;
        q.push(root);
		// BFS here!
        while (len) {
            while(len--) {
                // extracting the front of the queue
                root = q.front();
                q.pop();
                res += ',';
                if (root->left) {
                    res += to_string(root->left->val);
                    // adding the next node only if meaningful - if it has children
                    q.push(root->left);
                }
                res += ',';
                if (root->right) {
                    res += to_string(root->right->val);
                    // adding the next node only if meaningful - if it has children
                    q.push(root->right);
                }
            }
            len = q.size();
        }
        return res;
    }
    
    // decoding logic
    int pos = 0;
    int readString(string &s) {
        string tmp = "";
        while(pos < s.size() && s[pos] != ',') tmp += s[pos++];
        pos++;
        return tmp.size() ? stoi(tmp) : INT_MIN;
    }

    TreeNode* deserialize(string ser) {
        if (!ser.size()) return NULL;
        int len = 1, nextVal;
        TreeNode *root = new TreeNode(readString(ser)), *curr;
        queue<TreeNode*> q;
        q.push(root);
        while (len) {
            while(len--) {
                // extracting the front of the queue
                curr = q.front();
                q.pop();
                // adding left and right branches if present to both the tree and the queue
                nextVal = readString(ser);
                if (nextVal != INT_MIN) {
                    curr->left = new TreeNode(nextVal);
                    q.push(curr->left);
                }
                nextVal = readString(ser);
                if (nextVal != INT_MIN) {
                    curr->right = new TreeNode(nextVal);
                    q.push(curr->right);
                }
            }
            len = q.size();
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;