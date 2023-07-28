//Problem link: https://www.codingninjas.com/studio/problems/rod-cutting-problem_800284?leftPanelTab=1
//Recursive DP
//TC: O(N*N) SC: O(N*N)
private static int work(int price[],int dp[][],int ind,int n){
		if(ind==0) return n*price[0];
		if(dp[ind][n]!=-1) return dp[ind][n];
		int notcut = work(price,dp,ind-1,n);
		int cut = 0;
		if(ind+1<=n){
			cut =  price[ind] + work(price,dp,ind,n-ind-1);
		}
		dp[ind][n]= Math.max(notcut,cut);
		return dp[ind][n];
	}
	
	public static int cutRod(int price[], int n) {
		// Write your code here
		int  dp[][] = new int[n][n+1];
		for(int i=0;i<n;i++){
			for(int j=0;j<=n;j++){
				dp[i][j]=-1;
			}
		}
		return work(price,dp,n-1,n);
	}
//TC:O(N*N) SC:O(N*N)
class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n,vector<int>(n+1,0));
        for(int i=0;i<=n;i++){
            dp[0][i]=i*price[0]; //base case where we cut the only piece into n different rods
        }
        for(int i=1;i<n;i++){
            for(int l=0;l<=n;l++){
                int nottake= dp[i-1][l];
                int take=INT_MIN;
                if(i+1<=l) take=price[i]+dp[i][l-(i+1)];
                dp[i][l]=max(take,nottake);
            }
        }
        return dp[n-1][n];
    }
};

//Space optimization (Double array optimization)
//TC:O(N^2) SC:O(2*N)
class Solution{
  public:
    int cutRod(int price[], int n) {
       
        vector<int> prev(n+1,0),cur(n+1,0);
        
        for(int i=0;i<=n;i++){
            prev[i]=i*price[0]; //base case where we cut the only piece into n different rods
        }
        for(int i=1;i<n;i++){
            for(int l=0;l<=n;l++){
                int nottake= prev[l];
                int take=INT_MIN;
                if(i+1<=l) take=price[i]+cur[l-(i+1)];
                cur[l]=max(take,nottake);
            }
            prev=cur;
        }
        return prev[n];
    }
};


//Single array optimization
class Solution{
  public:
    int cutRod(int price[], int n) {
      
        vector<int> prev(n+1,0);
        
        for(int i=0;i<=n;i++){
            prev[i]=i*price[0]; //base case where we cut the only piece into n different rods
        }
        for(int i=1;i<n;i++){
            for(int l=0;l<=n;l++){
                int nottake= prev[l];
                int take=INT_MIN;
                if(i+1<=l) take=price[i]+prev[l-(i+1)];
                prev[l]=max(take,nottake);
            }
            
        }
        return prev[n];
    }
};
