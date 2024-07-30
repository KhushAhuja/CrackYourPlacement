class Solution {
public:
    int uniquePaths(int m, int n) {
        //m+n-2Cn-1
        long long ans=1;
        for(int i=m;i<=(m+n-2);i++){
            ans*=i;
            ans/=(i-m+1);
        }
        return ans;
    }
};