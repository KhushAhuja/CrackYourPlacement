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
    TreeNode* createMergedTree(TreeNode* node1, TreeNode* node2){
        TreeNode* node;
        if(node1==nullptr and node2==nullptr) return nullptr;
        else if(node2==nullptr){
            node=new TreeNode(node1->val);
            node->left=createMergedTree(node1->left, nullptr);
            node->right=createMergedTree(node1->right, nullptr);
        }
        else if(node1==nullptr){
            node=new TreeNode(node2->val);
            node->left=createMergedTree(nullptr,node2->left);
            node->right=createMergedTree(nullptr,node2->right);
        }
        else{
            node=new TreeNode(node1->val+node2->val);
            node->left=createMergedTree(node1->left,node2->left);
            node->right=createMergedTree(node1->right,node2->right);
        }
        return node;
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode *root = createMergedTree(root1, root2);
        return root;
    }
};