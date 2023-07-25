//prob link: https://www.codingninjas.com/studio/problems/ninja-and-his-friends_3125885
//TC: O(9*R*C*C) SC: (r*C*c)
import java.util.* ;
import java.io.*; 
public class Solution {
	private static int maxchoc(int i,int j1,int j2,int[][] grid,int[][][] dp,int r,int c){
		if(j1<0 || j1>=c || j2<0 || j2>=c){
			return -10000000;
		}
		if(i==r-1){
			if(j1==j2){
				return grid[i][j1];
			}else{
				return grid[i][j1]+grid[i][j2];
			}
		}
		if(dp[i][j1][j2]!=-1){
			return dp[i][j1][j2];
		}
		int ans=0;
		for(int di = -1;di<=1;di++){
			for(int dj = -1;dj<=1;dj++){
				if(j1==j2){
					ans = Math.max(ans,grid[i][j1] + maxchoc(i+1, j1+di, j2+dj, grid, dp, r, c));
				}else{
					ans = Math.max(ans,grid[i][j1]+grid[i][j2]+ maxchoc(i+1, j1+di, j2+dj, grid, dp, r, c));
				}
			}
		}
		dp[i][j1][j2] = ans;
		return dp[i][j1][j2];
	}
	public static int maximumChocolates(int r, int c, int[][] grid) {
		// Write your code here.
		int[][][] dp = new int[r][c][c];
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				for(int k=0;k<c;k++){
					dp[i][j][k]=-1;
				}
			}

		}
		return maxchoc(0,0,c-1,grid,dp,r,c);

	}
}

//Iterative DP
int maximumChocolates(int n, int m, vector < vector < int >> & grid) {
  // Write your code here.
  vector < vector < vector < int >>> dp(n, vector < vector < int >> (m, 
  vector < int > (m, 0)));

  for (int j1 = 0; j1 < m; j1++) {
    for (int j2 = 0; j2 < m; j2++) {
      if (j1 == j2)
        dp[n - 1][j1][j2] = grid[n - 1][j1];
      else
        dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
    }
  }

  //Outer Nested Loops for travering DP Array
  for (int i = n - 2; i >= 0; i--) {
    for (int j1 = 0; j1 < m; j1++) {
      for (int j2 = 0; j2 < m; j2++) {

        int maxi = INT_MIN;

        //Inner nested loops to try out 9 options
        for (int di = -1; di <= 1; di++) {
          for (int dj = -1; dj <= 1; dj++) {

            int ans;

            if (j1 == j2)
              ans = grid[i][j1];
            else
              ans = grid[i][j1] + grid[i][j2];

            if ((j1 + di < 0 || j1 + di >= m) ||
              (j2 + dj < 0 || j2 + dj >= m))

              ans += -1e9;
            else
              ans += dp[i + 1][j1 + di][j2 + dj];

            maxi = max(ans, maxi);
          }
        }
        dp[i][j1][j2] = maxi;
      }
    }
  }

  return dp[0][0][m - 1];

}

//Space optimization
//we need only i+1'th row at every instance, so we use a 2-D dp cache
int maximumChocolates(int n, int m, vector < vector < int >> & grid) {
  // Write your code here.
  vector < vector < int >> front(m, vector < int > (m, 0)), cur(m, vector < int > 
  (m, 0));

  for (int j1 = 0; j1 < m; j1++) {
    for (int j2 = 0; j2 < m; j2++) {
      if (j1 == j2)
        front[j1][j2] = grid[n - 1][j1];
      else
        front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
    }
  }

  //Outer Nested Loops for travering DP Array
  for (int i = n - 2; i >= 0; i--) {
    for (int j1 = 0; j1 < m; j1++) {
      for (int j2 = 0; j2 < m; j2++) {

        int maxi = INT_MIN;

        //Inner nested loops to try out 9 options
        for (int di = -1; di <= 1; di++) {
          for (int dj = -1; dj <= 1; dj++) {

            int ans;

            if (j1 == j2)
              ans = grid[i][j1];
            else
              ans = grid[i][j1] + grid[i][j2];

            if ((j1 + di < 0 || j1 + di >= m) ||
              (j2 + dj < 0 || j2 + dj >= m))

              ans += -1e9;
            else
              ans += front[j1 + di][j2 + dj];

            maxi = max(ans, maxi);

          }
        }
        cur[j1][j2] = maxi;
      }
    }
    front = cur;
  }

  return front[0][m - 1];

}
