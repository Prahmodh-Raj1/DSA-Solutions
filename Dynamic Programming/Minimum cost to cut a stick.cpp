//Problem link: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
class Solution {
public:
//TC:O(N^3) SC:O(N^2)
    int func(int i,int j,vector<int>& cuts,vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=1e9;
        for(int k=i;k<=j;k++){
            int ans=cuts[j+1]-cuts[i-1] + func(i,k-1,cuts,dp)+ func(k+1,j,cuts,dp);
            mini=min(mini,ans);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        int l=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        //we can do the cutting independently if we sort the cuts then partition
        //cost when we cut at posn cuts[i], is the length of the portion in which cuts[i] is present
        //The cost is given by cuts[i-1]+cuts[j-1]
        vector<vector<int>> dp(l+2,vector<int>(l+2,0));  //declaring size as l+2 since when j=l, then index j+1 might go out of bounds, so we avoid that
        for(int i=l;i>=1;i--){
            for(int j=1;j<=l;j++){
                if(i>j) continue;
                int mini=1e9;
                for(int k=i;k<=j;k++){
                    int ans=cuts[j+1]-cuts[i-1]+ dp[i][k-1]+dp[k+1][j];
                    mini=min(ans,mini);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][l];

        //return func(1,l,cuts,dp);
    }
};
