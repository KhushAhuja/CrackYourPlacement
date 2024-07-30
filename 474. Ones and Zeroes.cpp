class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        int N=strs.size();
        for(int i=0;i<N;i++){
            int count0=0;
            int count1=0;
            for(auto s:strs[i]){
                if(s=='1') count1++;
                else count0++;
            }
            if(count0<=m and count1<=n){
                for(int j=m;j>=count0;j--){
                    for(int k=n;k>=count1;k--){
                        dp[j][k]=max(dp[j][k],1+dp[j-count0][k-count1]);
                    }
                }
            }
        }
        return dp[m][n];
    }
};