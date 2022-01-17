//prob link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
//TC :O(N)  SC: O(N)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0){
            return 0;
        }
        int min=INT_MAX;
        vector<int> mini;
        int profit=0;
        int n=prices.size();
        for(int i=0;i<n;i++){
            if(prices[i]<min){
                min=prices[i];
                mini.push_back(prices[i]);
            }if(prices[i]>mini[mini.size()-1]){
                profit+=prices[i]-mini[mini.size()-1];
                mini[mini.size()-1]=prices[i];
                min=prices[i];
            }
        }
        return profit;
    }
};
//TC :O(N)  SC:O(1)
     int maxProfit(vector<int>& prices) {
        int ans=0,profit=0;
        int valley,peak;
        for(int i=0;i<prices.size();i++)
        {
            while(i<prices.size()-1 && prices[i]>=prices[i+1])i++;
            valley = prices[i];
            while(i<prices.size()-1 && prices[i]<=prices[i+1])i++;
            peak = prices[i];
            profit += peak-valley;
        }
        return profit;
    }
