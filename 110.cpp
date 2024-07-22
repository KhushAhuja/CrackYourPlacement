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
    bool ans=true;

    int maxDepth(TreeNode* node){
        if(node==nullptr) return 0;
        int left=maxDepth(node->left);
        int right=maxDepth(node->right);
        if(abs(left-right)>1) ans=false;
        return 1+max(left,right);
    }

    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;
        maxDepth(root);
        return ans;
    }
};