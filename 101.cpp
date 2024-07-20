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
    void inOrder(TreeNode* node, vector<pair<int,int>> &inorder, int dir){
        if(node==NULL) return;
        inOrder(node->left, inorder, -1);
        inorder.push_back({node->val,dir});
        inOrder(node->right, inorder, 1);
    }

    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        vector<pair<int,int>> inorder;
        inOrder(root, inorder, 0);
        for(int i=0;i<inorder.size()/2;i++){
            if(inorder[i].first!=inorder[inorder.size()-1-i].first or inorder[i].second==inorder[inorder.size()-1-i].second) return false;
        }
        return true;
    }
};