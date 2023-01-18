
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
