class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int lp=0;
        int rp=n-1;
        while(lp<n and nums[lp]==0) lp++;
        for(int i=lp+1;i<n;i++){
            if(nums[i]==0) swap(nums[i],nums[lp]);
            while(lp<n and nums[lp]==0) lp++;

        }
        while(rp>=0 and nums[rp]==2) rp--;
        for(int i=rp-1;i>=lp;i--){
            if(nums[i]==2) swap(nums[i],nums[rp]);
            while(rp>=0 and nums[rp]==2) rp--;

        }
    }
};