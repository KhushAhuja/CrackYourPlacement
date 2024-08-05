class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]!="+" and tokens[i]!="*" and tokens[i]!="-" and tokens[i]!="/"){
                s.push(stoi(tokens[i]));
            }
            else{
                int x=s.top();
                s.pop();
                if(tokens[i]=="+") x=s.top()+x;
                if(tokens[i]=="*") x=s.top()*x;
                if(tokens[i]=="/") x=s.top()/x;
                if(tokens[i]=="-") x=s.top()-x;
                s.pop();
                s.push(x);
            }
        }
        return s.top();
    }
};