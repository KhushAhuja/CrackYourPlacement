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
    bool isSametree(TreeNode* root, TreeNode* subRoot){
        if(root==nullptr and subRoot==nullptr) return true;
        if(root==nullptr or subRoot==nullptr) return false;
        bool left=isSametree(root->left, subRoot->left);
        bool right=isSametree(root->right, subRoot->right);
        return left&&right&&(root->val==subRoot->val);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr) return false;
        if(root->val==subRoot->val and isSametree(root, subRoot)) return true;
        bool left=isSubtree(root->left, subRoot);
        bool right=isSubtree(root->right, subRoot);
        return left || right;
    }
};