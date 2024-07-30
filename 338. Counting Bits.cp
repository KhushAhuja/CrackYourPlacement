class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            int hp=log2(i);
            int hval=1<<hp;
            dp[i]=1+dp[i-hval];
        }
        return dp;
    }
};