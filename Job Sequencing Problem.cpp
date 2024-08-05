static auto comp(Job a, Job b) {
        return a.profit > b.profit; 
    };
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr + n, comp);
        int max_deadline=arr[0].dead;
        for(int i=1;i<n;i++){
            max_deadline=max(max_deadline, arr[i].dead);
        }
        vector<int> dp(max_deadline+1,-1);
        int jc=0;
        int prf=0;
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>=1;j--){
                if(dp[j]==-1){
                    jc++;
                    prf+=arr[i].profit;
                    dp[j]=1;
                    break;
                }
            }
        }
        vector<int> ans;
        ans.push_back(jc);
        ans.push_back(prf);
        
        return ans;
    } 