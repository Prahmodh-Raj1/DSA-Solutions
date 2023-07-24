//Problem link: https://www.codingninjas.com/studio/problems/ninja%E2%80%99s-training_3621003?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0
//TC: O(N) SC: O(N*3)
import java.util.*;
public class Solution {
    public static int maxim(int dp[][],int n,int task,int points[][]){
        if(n==0){
            int maxi=-1;
            for(int i=0;i<=2;i++){
                if(i!=task){
                    maxi=Math.max(maxi,points[0][i]);
                }
            }
            return maxi;
        }
        if(dp[n][task]!=-1) return dp[n][task];
        int maxx=0;
        for(int i=0;i<=2;i++){
            if(i!=task){
                int point=points[n][i] + maxim(dp,n-1,i,points);
                maxx=Math.max(point,maxx);
            }
        }
        dp[n][task]=maxx;
        return dp[n][task];
    }
    public static int ninjaTraining(int n, int points[][]) {
        int dp[][] = new int[n][3];
        for(int[] row:dp)
            Arrays.fill(row,-1);
        dp[0][0] = points[0][0];
        dp[0][1]= points[0][1];
        dp[0][2] = points[0][2];
        for(int i=1;i<n;i++){
            int act1 = points[i][0] + Math.max(dp[i-1][1],dp[i-1][2]);
            int act2 = points[i][1] + Math.max(dp[i-1][0],dp[i-1][2]);
            int act3 = points[i][2] + Math.max(dp[i-1][0],dp[i-1][1]);
            dp[i][0]= act1;
            dp[i][1] = act2;
            dp[i][2]= act3;
             
        }
        int ans=-1;
        for(int j=0;j<3;j++){
            ans = Math.max(ans,dp[n-1][j]);
        }
        return ans;
        
        //return maxim(dp,n-1,3,points);
        
        // Write your code here..
    }

}
