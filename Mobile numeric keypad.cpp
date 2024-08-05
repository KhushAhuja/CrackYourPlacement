long long helper(int dig, int n, vector<vector<long long>>& dp) {
        if (dp[n][dig] != -1) return dp[n][dig];
        long long count = 0;
        if (n == 1) return dp[n][dig] = 1;
    
        if (dig == 1) {
            count = helper(1, n - 1, dp) + helper(2, n - 1, dp) + helper(4, n - 1, dp);
        } else if (dig == 2) {
            count = helper(1, n - 1, dp) + helper(2, n - 1, dp) + helper(3, n - 1, dp) + helper(5, n - 1, dp);
        } else if (dig == 3) {
            count = helper(2, n - 1, dp) + helper(3, n - 1, dp) + helper(6, n - 1, dp);
        } else if (dig == 4) {
            count = helper(1, n - 1, dp) + helper(4, n - 1, dp) + helper(5, n - 1, dp) + helper(7, n - 1, dp);
        } else if (dig == 5) {
            count = helper(2, n - 1, dp) + helper(4, n - 1, dp) + helper(5, n - 1, dp) + helper(6, n - 1, dp) + helper(8, n - 1, dp);
        } else if (dig == 6) {
            count = helper(3, n - 1, dp) + helper(5, n - 1, dp) + helper(6, n - 1, dp) + helper(9, n - 1, dp);
        } else if (dig == 7) {
            count = helper(4, n - 1, dp) + helper(7, n - 1, dp) + helper(8, n - 1, dp);
        } else if (dig == 8) {
            count = helper(5, n - 1, dp) + helper(7, n - 1, dp) + helper(8, n - 1, dp) + helper(9, n - 1, dp) + helper(0, n - 1, dp);
        } else if (dig == 9) {
            count = helper(6, n - 1, dp) + helper(8, n - 1, dp) + helper(9, n - 1, dp);
        } else if (dig == 0) {
            count = helper(0, n - 1, dp) + helper(8, n - 1, dp);
        }
    
        return dp[n][dig] = count;
    }
  
    long long getCount(int n) {
        // Your code goes here
        vector<vector<long long>> dp(n+1, vector<long long>(10,-1));
        long long ans=0;
        for(int i=0;i<=9;i++){
            dp[1][i]=1;
        }
        for(int i=0;i<=9;i++){
            ans+=helper(i,n,dp);
        
        }
        return ans;
    }