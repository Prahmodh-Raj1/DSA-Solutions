//Problem link: https://leetcode.com/problems/ones-and-zeroes
//TC& SC: O(N*Ones*Zeroes)
class Solution {
public:
    //we either include the string to our subset or we leave it ,depending on the number of zeroes and ones we need
    int func(int i,int m,int n,vector<string>& strs,vector<vector<vector<int>>>& dp,vector<pair<int,int>>& v){
        if(i>=strs.size() or (m==0 and n==0)) return  0;  //when we have reached the end of the string or we have reached the zero and one limit
        if(dp[i][m][n]!=-1) return dp[i][m][n];
        int nottake = func(i+1,m,n,strs,dp,v);
        int take=0;
        if(v[i].first<=m and v[i].second<=n){
            take = 1 + func(i+1,m-v[i].first,n-v[i].second,strs,dp,v);
        } 
        return dp[i][m][n]=max(take,nottake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l=strs.size();
        vector<vector<vector<int>>> dp(l,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        
        vector<pair<int,int>> v; //contains the number of zeroes and ones for each string
        for(int k=0;k<l;k++){
            int zeroes= count(strs[k].begin(),strs[k].end(),'0');
            int ones = count(strs[k].begin(),strs[k].end(),'1');
            v.push_back({zeroes,ones});
        }
        
        return func(0,m,n,strs,dp,v);
    }
};
