class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int flag=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1] and flag==0){
                profit-=prices[i-1];
                flag=1;
            }
            if(prices[i]<prices[i-1] and flag==1){
                profit+=prices[i-1];
                flag=0;
            }
        }
        if(flag) profit+=prices[prices.size()-1];
        return profit;
    }
};