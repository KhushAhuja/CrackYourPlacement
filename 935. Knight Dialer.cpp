class Solution {
public:
    int knightDialer(int n) {
        long long mod = 1e9+7;
        vector<vector<long long>> dp(10, vector<long long>(n+1,0));
        for(int i=0;i<10;i++){
            dp[i][1]=1;
        }
        for(int i=2;i<=n;i++){
            for(int j=0;j<10;j++){
                if(j==0) dp[j][i]+=dp[4][i-1]+dp[6][i-1];
                if(j==1) dp[j][i]+=dp[8][i-1]+dp[6][i-1];
                if(j==2) dp[j][i]+=dp[7][i-1]+dp[9][i-1];
                if(j==3) dp[j][i]+=dp[4][i-1]+dp[8][i-1];
                if(j==4) dp[j][i]+=dp[0][i-1]+dp[3][i-1]+dp[9][i-1];
                if(j==6) dp[j][i]+=dp[0][i-1]+dp[1][i-1]+dp[7][i-1];
                if(j==7) dp[j][i]+=dp[2][i-1]+dp[6][i-1];
                if(j==8) dp[j][i]+=dp[1][i-1]+dp[3][i-1];
                if(j==9) dp[j][i]+=dp[2][i-1]+dp[4][i-1];
                dp[j][i]%=mod;
            }
        }
        int ans=0;
        for(int i=0;i<10;i++){
            ans+=dp[i][n];
            ans%=mod;
        }
        return ans;
    }
};