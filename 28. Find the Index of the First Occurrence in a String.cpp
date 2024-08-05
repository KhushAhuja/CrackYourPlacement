//KMP STRING MATCHING

class Solution {
public:
    vector<int> computePrefix(string s){
        int n=s.size();
        vector<int> pre(n,0);
        for(int i=1;i<n;i++){
            int j=pre[i-1];
            while(j>0 and s[i]!=s[j]) j=pre[j-1];
            if(s[i]==s[j]) j++;
            pre[i]=j;
        }
        return pre;
    }

    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        vector<int> pre=computePrefix(needle);
        int i=0,j=0;
        int pos=-1;
        while(i<n){
            if(haystack[i]==needle[j]){
                j++;
                i++;
            }
            else{
                if(j!=0) j=pre[j-1];
                else i++;
            }
            if(j==m){
                pos=i-m;
                break;
            }
        }
        return pos;
    }
};