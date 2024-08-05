class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        int i=INT_MAX;
        for(int j=0;j<n;j++){
            int x=(strs[j].size());
            i=min(i,x);
        }
        int cnt=0;
        while(cnt<i){
            int flag=0;
            for(int j=1;j<n;j++){
                if(strs[j][cnt]!=strs[j-1][cnt]){
                    flag=1;
                    break;
                } 
            }
            if(flag) break;
            cnt++;
        }
        cnt--;
        if(cnt>=0){
            return strs[0].substr(0,cnt+1);
        }
        return "";
    }
};