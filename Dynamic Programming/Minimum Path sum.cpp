//Problem link: https://leetcode.com/problems/minimum-path-sum/
//TC :O(N^2) SC:O(N^2)
class Solution {
public:
    int dp[201][201];
    int summ(vector<vector<int>>& grid,int i,int j){
        if(i<0 or j<0) return 1e9;
        if(i==0 and j==0) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j]=min(summ(grid,i-1,j),summ(grid,i,j-1))+grid[i][j];
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        //dp[0][0]=grid[0][0];
        return summ(grid,grid.size()-1,grid[0].size()-1);
    }
};

//Space optimised approach
//TC:O(N^2) SC:O(N)

int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
       
        vector<int> prev(n,0);

        for(int i=0;i<m;i++){
            vector<int> cur(n,0);
            for(int j=0;j<n;j++){
                if(i==0 and j==0){
                    cur[j]=grid[i][j];
                }
                else{
                    int up=grid[i][j],left=grid[i][j];
                    if(i>0){  
                        up+=prev[j];
                    }else{
                        up+=1e9;
                    }
                    if(j>0) left+=cur[j-1];  
                    else left+=1e9;
                    cur[j]=min(up,left);
                }
            }
            prev=cur;
        }
        return prev[n-1];
    }
