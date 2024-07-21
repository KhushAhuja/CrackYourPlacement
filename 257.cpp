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
    vector<string> paths;

    void pathTracker(TreeNode* node,string path){
        if(node==nullptr) return;
        if(node->left==nullptr and node->right==nullptr){
            paths.push_back(path+to_string(node->val));
            return;
        }
        pathTracker(node->left, path+to_string(node->val)+"->");
        pathTracker(node->right, path+to_string(node->val)+"->");
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        pathTracker(root,"");
        return paths;
    }
};