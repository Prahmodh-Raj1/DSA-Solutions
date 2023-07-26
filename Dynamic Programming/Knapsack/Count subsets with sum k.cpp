//Problem link: https://www.codingninjas.com/studio/problems/count-subsets-with-sum-k_3952532
//TC: O(N*K) SC: O(N*K)
#include <bits/stdc++.h> 
/*int findWays(vector<int> &num, int k){
     int n = num.size();

    vector<vector<int>> dp(n,vector<int>(k+1,0));
    
    for(int i=0; i<n; i++){
        dp[i][0] = 1;  //sum zero os always possible
    }
    
    if(num[0]<=k)
        dp[0][num[0]] = 1;  //it's possible if the first element is less than k, the base case
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 1; target<=k; target++){
            
            int notTaken = dp[ind-1][target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = dp[ind-1][target-num[ind]];
        
            dp[ind][target]= notTaken + taken;
        }
    }
    
    return dp[n-1][k];
    
}*/
const int mod = 1e9 + 7;
int helper(int ind,vector<int>& num,int sum,vector<vector<int>>& dp,int k){
    if(sum==k) return 1;
    if(ind==num.size()){
        return 0;
    }
    if(dp[ind][sum]!=-1){
        return dp[ind][sum];
    }
    int nottake = helper(ind+1,num,sum,dp,k)%mod;
    
    int take = 0;
    if (sum + num[ind] <= k) {
      take = (helper(ind + 1, num, sum + num[ind], dp, k))%mod;
    }
    return dp[ind][sum] = (take+nottake)%mod;
}
int findWays(vector<int>& num,int k){
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return helper(0,num,0,dp,k)%mod;
}
