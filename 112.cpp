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
    bool solve(TreeNode* root, int sum, int target){
        if(root==NULL){
            return false;
        }
        sum+=root->val;
        if(root->right==NULL and root->left==NULL){
            if(sum==target) return true;
            else return false;
        }
        return (solve(root->left,sum,target) or solve(root->right,sum,target));

    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        return solve(root,0,targetSum);
    }
};