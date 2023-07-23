//Prob link: https://leetcode.com/problems/minimum-falling-path-sum-ii
//TC: O(M*N*N) SC: O(M*N)
public int minFallingPathSum(int[][] grid) {
        int n= grid.length;
        int[][] dp = new int[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=0;
            }
        }
        for(int j=0;j<n;j++){
            dp[0][j] = grid[0][j];
        }
        for(int i=1;i<n;i++){
            //for the current column
            
            for(int j=0;j<n;j++){
                int mini=Integer.MAX_VALUE;
                for(int k=0;k<n;k++){
                    if(k!=j){
                        mini =Math.min(mini,dp[i-1][k]);
                    }
                }
                dp[i][j] = grid[i][j] + mini;
            }
        }
        
        int ans=Integer.MAX_VALUE;
        for(int j=0;j<n;j++){
            ans = Math.min(ans,dp[n-1][j]);
        }
        return ans;
    }

//TC: O(M*N) SC: O(M*N)
int dp[210][210];
int n;
int help(int i , int j , vector<vector<int>>& a)
{
    if(i<0 or i>=n or j< 0 or j>=n)  return 0;
    int &ans = dp[i][j];
    if(ans != INT_MAX)   return ans;
    // ans = INT_MAX;
    for(int c=0;c<n;c++)
    {
        if(c == j and i!=0)
            continue;
        ans = min(ans , a[i][c] + help(i+1 , c , a));
    }
    return ans ;
}

int minFallingPathSum(vector<vector<int>>& a) 
{
    n = a.size();
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            dp[i][j] = INT_MAX;
    return help(0,0,a);
}
