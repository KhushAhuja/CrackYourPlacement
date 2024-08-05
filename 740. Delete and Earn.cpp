class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto i:nums) m[i]++;
        vector<int> dp(10001,0);
        dp[1]=m[1]*1;
        for(int i=2;i<10001;i++){
            if(m.find(i)!=m.end()){
                dp[i]=max(dp[i-1],dp[i-2]+m[i]*i);
            }
            else dp[i]=dp[i-1];
        }
        return dp[10000];
    }
};