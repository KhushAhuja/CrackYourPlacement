class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        unordered_map<int,int> m;
        m[0]=1;
        int ans=0;
        for(int i=0;i<n;i++){
            int mod=nums[i]%k;
            if(mod<0) mod+=k;    //important line(concept)
            if(m.count(mod)!=0){
                ans+=m[mod];
            }
            m[mod]++;
        }
        return ans;
    }
};