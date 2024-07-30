class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> s;
        int p=-1;
        int k=0;
        for(int i=0;i<nums.size();i++){
            int ele=nums[i];
            if(s.find(nums[i])!=s.end()){
                if(p==-1) p=i;
            }
            else{
                k++;
                if(p!=-1){
                    swap(nums[p], nums[i]);
                    cout<<p<<" "<<i<<endl;
                    p++;
                }
            }
            s.insert(ele);
        }
        return k;
    }
};