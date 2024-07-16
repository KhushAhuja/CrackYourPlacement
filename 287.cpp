class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            while((nums[i]-1)!=i){
                if(nums[i]==nums[nums[i]-1]) return nums[i];
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        return -1;
    }
};