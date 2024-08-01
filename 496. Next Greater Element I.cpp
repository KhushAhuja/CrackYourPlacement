class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        unordered_map<int,pair<int,int>> m;
        for(int i=0;i<n1;i++) m[nums1[i]]={i,-1};
        stack<int> st;
        vector<int> ans(n1,-1);
        for(int i=n2-1;i>=0;i--){
            if(m.find(nums2[i])!=m.end()){
                while(!st.empty()){
                    int x=st.top();
                    if(x>nums2[i]){
                        ans[m[nums2[i]].first]=x;
                        break;
                    } 
                    st.pop();
                }
            } 
            st.push(nums2[i]);
        }
        return ans;
    }
};