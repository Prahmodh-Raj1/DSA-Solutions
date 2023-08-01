//Problem link: https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
//TC: O(N^3) SC: O(N^2)

//Recursive DP
class Solution{
    private static int work(int i,int j,int arr[],int dp[][]){
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=Integer.MAX_VALUE;
        for(int k=i;k<j;k++){
            int steps = arr[i-1]*arr[k]*arr[j] + work(i,k,arr,dp) + work(k+1,j,arr,dp);
            mini = Math.min(steps,mini);
        }
        dp[i][j]=mini;
        return dp[i][j];
    }
    static int matrixMultiplication(int N, int arr[])
    {
        // code here
        int dp[][] = new int[N][N];
        for(int rows[]: dp){
            Arrays.fill(rows,-1);
        }
        return work(1,N-1,arr,dp);
    }
}

//Iterative DP
public class Solution {

	
	public static int mcm(int[] p){
	
		int n = p.length;
		int dp[][] = new int[n][n];
		for(int i=0;i<n;i++){
			dp[i][i] = 0; //cost for multiplying a single matrix is zero
		}
		for(int i=n-1;i>=1;i--){
			for(int j=i+1;j<n;j++){
				int mini = Integer.MAX_VALUE;
				for(int k=i;k<j;k++){
					mini = Math.min(mini,p[i-1]*p[k]*p[j] + dp[i][k] + dp[k+1][j]);
				}
				dp[i][j] = mini;
			}
		}
		return dp[1][n-1];

	}


	
}
