class Solution
{
    public:
    void solveSuc(Node* node, Node*& suc){
        if(node==nullptr) return;
        suc=node;
        solveSuc(node->left,suc);
    }
    
    void solvePre(Node* node, Node*& pre){
        if(node==nullptr) return;
        pre=node;
        solvePre(node->right,pre);
    }
    
    void findNode(Node* node, Node*& pre, Node*& suc, int key){
        if(node==nullptr) return;
        if(node->key==key){
            solvePre(node->left,pre);
            solveSuc(node->right,suc);
            return;
        } 
        if(node->key>key){
            suc=node;
            findNode(node->left,pre,suc,key);
        }
        else{
            pre=node;
            findNode(node->right,pre,suc,key);
        }
    }
    
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        suc=nullptr;
        pre=nullptr;
        findNode(root,pre,suc,key);
    }
};