class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> s;
        int n=temperatures.size();
        vector<int> ans(n,0);
        s.push({temperatures[0],0});
        for(int i=1;i<temperatures.size();i++){
            while(!s.empty() and temperatures[i]>s.top().first){
                ans[s.top().second]=i-s.top().second;
                s.pop();
            }
            s.push({temperatures[i],i});
        }
        
        return ans;
    }
};