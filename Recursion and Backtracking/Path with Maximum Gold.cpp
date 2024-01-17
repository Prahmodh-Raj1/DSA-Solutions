//Problem link: https://leetcode.com/problems/path-with-maximum-gold
//TC: O(4*k) SC: O(Stack space)
class Solution {
private:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    int movement(vector<vector<int>>& grid,int i,int j,int m,int n){
        if(i>=m or j>=n or i<0 or j<0 or grid[i][j]==0) return 0;
        int initialvalue = grid[i][j];
        grid[i][j]=0;   //marking as visited
        int maxg=0;
        for(int r=0;r<4;r++){
            int ni = dx[r]+i;
            int nj = dy[r]+j;
            maxg = max(maxg,movement(grid,ni,nj,m,n));
            
        }
        grid[i][j]=initialvalue;  //backtracking
        
        return maxg+initialvalue;
        
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size();
        int n= grid[0].size();
        int maxi=-1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                maxi= max(maxi,movement(grid,i,j,m,n));
                
            }
        }
        return maxi;

    }
};
