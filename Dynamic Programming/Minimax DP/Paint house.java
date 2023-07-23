//Prob link: https://www.codingninjas.com/studio/problems/paint-house_1460385?leftPanelTab=1
//TC: O(N) SC: O(N*3)
import java.util.*;

public class Solution {
    public static int minCost(int[][] cost) {
        // Write your code here.
        int n=cost.length;
        int[][] dp = new int[n][3];
        for(int i=0;i<n;i++){
            dp[i][0]=0;
            dp[i][1]=0;
            dp[i][2]=0;
        }
        dp[0][0]=cost[0][0];
        dp[0][1] = cost[0][1];
        dp[0][2] = cost[0][2];  //base cases
        for(int i=1;i<n;i++){
            int color0 = cost[i][0] + Math.min(dp[i-1][1],dp[i-1][2]);
            //if we painted house i with color 0, the cost is calculated
            //as cost[i][color] + min(prev house when painted with other two colors)
            int color1 = cost[i][1] + Math.min(dp[i-1][0],dp[i-1][2]);
            int color2 = cost[i][2]  + Math.min(dp[i-1][0],dp[i-1][1]);
            dp[i][0]=color0;
            dp[i][1] = color1;
            dp[i][2] = color2;

        }
        int ans = Math.min(dp[n-1][0],dp[n-1][1]);
        ans = Math.min(ans,dp[n-1][2]);
        return ans;
       
    }
}
