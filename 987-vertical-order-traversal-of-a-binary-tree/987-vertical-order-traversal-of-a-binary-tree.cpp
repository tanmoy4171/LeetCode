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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        // avoiding empty trees
        if (!root) return res;
        int minL = 0, maxR = 0, len, x;
        TreeNode *currNode;
        unordered_map<int, vector<int>> columnsMap;
        unordered_map<int, vector<int>> tmpMap;
        queue<pair<TreeNode*, int>> layer;
        layer.push({root, 0});
        // approaching the tree with a BFS approach
        while (layer.size()) {
            len = layer.size();
            tmpMap.clear();
            for (int i = 0; i < len; i++) {
                // picking each node in the current layer, with relevant x position
                currNode = layer.front().first;
                x = layer.front().second;
                // updating columnsMap accordingly
                tmpMap[x].push_back(currNode->val);
                // updating minL and maxR with the current value of x
                minL = min(minL, x);
                maxR = max(maxR, x);
                // adding left and right children to the queue, if they exist
                if (currNode->left) layer.push({currNode->left, x - 1});
                if (currNode->right) layer.push({currNode->right, x + 1});
                // removing the currently used node once we are done
                layer.pop();
            }
            for (auto e: tmpMap) {
                sort(begin(e.second), end(e.second));
                for (int n: e.second) columnsMap[e.first].push_back(n);
            }
        }
        for (int i = minL; i <= maxR; i++) {
            res.push_back(columnsMap[i]);
        }
        return res;
    }
};