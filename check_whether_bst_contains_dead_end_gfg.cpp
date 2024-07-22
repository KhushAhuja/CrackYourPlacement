class Solution{
  public:
    unordered_set<int> s;
    bool isDeadEnd(Node *root)
    {
        //Your code here
        if(root==nullptr) return false;
        s.insert(root->data);
        if(root->left==nullptr and root->right==nullptr){
            if(root->data==1 and s.find(root->data+1)!=s.end()) return true;
            else if(s.find(root->data-1)!=s.end() and s.find(root->data+1)!=s.end()) return true;
            else return false;
        }
        return isDeadEnd(root->left) or isDeadEnd(root->right);
        
    }
};