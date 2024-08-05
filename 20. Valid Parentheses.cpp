class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(!st.empty()){
                if((s[i]==')' and st.top()!='(') or (s[i]==']' and st.top()!='[') or (s[i]=='}' and st.top()!='{'))
                return false;
                if(s[i]==')' or s[i]=='}' or s[i]==']') st.pop();
                else st.push(s[i]);
            }
            else{
                if(s[i]==')' or s[i]=='}' or s[i]==']') return false;
                else st.push(s[i]);
            }
        }
        return ((st.empty())? true:false);
    }
};