//Problem link: https://www.codingninjas.com/codestudio/problems/frog-jump_3621012
//TC : O(N) SC: O(N)/O(1)
#include <bits/stdc++.h> 
int func(vector<int>& dp,int n,vector<int>& heights){
   
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int left=func(dp,n-1,heights)+abs(heights[n]-heights[n-1]);
    
    int right= INT_MAX;
    if(n>1) right=func(dp,n-2,heights)+abs(heights[n]-heights[n-2]);
    return dp[n]=min(left,right);
        
}
int frogJump(int n, vector<int> &heights)
{
  
    int prev2=0;
    int prev1=0;
    for(int i=1;i<n;i++){
        int ls=prev1+abs(heights[i-1]-heights[i]);
        int rs=INT_MAX;
        if(i>1){
            rs=prev2+abs(heights[i-2]-heights[i]);
        }
        int cur=min(ls,rs);
        prev2=prev1;
        prev1=cur;
    }
    return prev1;
    
}
