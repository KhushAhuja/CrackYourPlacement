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
    int maxi=0;
    int maxDepth(TreeNode* node){
        if(node==nullptr) return 0;
        int left=maxDepth(node->left);
        int right=maxDepth(node->right);
        maxi=max(left+right,maxi);
        return 1+max(left,right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        maxDepth(root);
        return maxi;
    }
};