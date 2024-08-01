class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#'){
                if(!st.empty()) st.pop();
            } 
            else st.push(s[i]);
        }
        int netsz=st.size();
        int hash=0;
        for(int i=t.size()-1;i>=0;i--){
            if(t[i]=='#') hash++;
            else if(hash>0){
                hash--;
            }
            else{
                if(st.empty()) return false;
                if(st.top()==t[i]) netsz--;
                st.pop();
            }
        }
        if (netsz>0) return false;
        return true;
    }
};