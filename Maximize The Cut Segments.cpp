int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int> dp(n+1,INT_MIN);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            if(i>=x) dp[i]=max(dp[i],dp[i-x]+1);
            if(i>=y) dp[i]=max(dp[i],dp[i-y]+1);
            if(i>=z) dp[i]=max(dp[i],dp[i-z]+1);
        }
        return max(dp[n],0);
    }