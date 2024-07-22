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
    vector<int> inorder;
    void inorderTraversal(TreeNode* node){
        if(node==nullptr) return;
        inorderTraversal(node->left);
        inorder.push_back(node->val);
        inorderTraversal(node->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inorderTraversal(root);
        int minDiff=INT_MAX;
        for(int i=1;i<inorder.size();i++){
            minDiff=min(minDiff,inorder[i]-inorder[i-1]);
        }
        return minDiff;
    }
};