//Problem link: https://leetcode.com/problems/triangle/description/
//TC :O(N^2) SC:O(N^2)
class Solution {
public:
    int dp[201][201];
    int func(int i,int j,vector<vector<int>>& grid){
        if(i==grid.size()-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int down=grid[i][j]+func(i+1,j,grid);
        int dg=grid[i][j]+func(i+1,j+1,grid);
        return dp[i][j]=min(down,dg);
    }
    int minimumTotal(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return func(0,0,grid);
    }
};

//Space optimized approach
//TC:O(N^2) SC:O(N)

int minimumTotal(vector<vector<int>>& grid) {
        int m=grid.size();
        
        vector<int> front(m,0),cur(m,0);
        for(int j=0;j<m;j++){  //base case covered
            front[j]=grid[m-1][j];
        }
        for(int i=m-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=grid[i][j]+front[j];
                int dg=grid[i][j]+front[j+1];
                
                cur[j]=min(dg,down);
            }
            front=cur;
        }
        return front[0];
    }
