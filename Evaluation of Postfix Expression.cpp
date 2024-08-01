int n=S.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(S[i]=='*'){
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                st.push(x*y);
            }
            else if(S[i]=='+'){
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                st.push(x+y);
            }
            else if(S[i]=='/'){
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                st.push(y/x);
            }
            else if(S[i]=='-'){
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                st.push(y-x);
            }
            else{
                st.push((S[i]-'0'));
            }
        }
        return st.top();