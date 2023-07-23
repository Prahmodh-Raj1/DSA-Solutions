//iterative and recursive dp
//Prob link: https://www.codingninjas.com/studio/problems/minimal-cost_8180930?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1
public class Solution {
    private static int work(int ind,int k,int[] dp,int[] heights,int n){
        if(ind==n-1){
            return 0;
        }
        if(ind>=n){
            return 10000000;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int mini=10000000;
        for(int i = 1;i<=k;i++){
            if(ind+i<n){
                mini=Math.min(mini,work(ind+i,k,dp,heights,n) + Math.abs(heights[ind]-heights[ind+i]));
            }
        }
        dp[ind] = mini;
        return dp[ind];
        
    }
    public static int minimizeCost(int n, int k, int []heights){
        // Write your code here.
        int[] dp = new int[n];
        for(int i=0;i<n;i++){
            dp[i]=-1;
        }
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--){
            int mini=10000000;
            for(int ind=1;ind<=k;ind++){
                if(i+ind<n){
                    mini=Math.min(mini,dp[i+ind]+Math.abs(heights[i]-heights[i+ind]));
                }
            }
            dp[i]=mini;
        }
        return dp[0];
    }
}
