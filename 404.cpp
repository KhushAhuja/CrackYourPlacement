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
    int sum=0;

    void checkValidLeaf(TreeNode* node,int dir){
        if(node==nullptr) return;
        if(node->left==nullptr and node->right==nullptr){
            if(dir==-1) sum+=node->val;
            return;
        }
        checkValidLeaf(node->left,-1);
        checkValidLeaf(node->right,1);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if(root==nullptr) return 0;
        checkValidLeaf(root,0);
        return sum;
    }
};
