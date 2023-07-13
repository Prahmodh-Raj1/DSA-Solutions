//Problem link: https://atcoder.jp/contests/abc293/tasks/abc293_c
//TC: O(2^(H+W))  SC: O(H*W)
int func(int i,int j,int n,int m,vector<vector<int>>& grid,set<int>& st){
  
  if(i==n-1 and j==m-1){
    if(st.find(grid[i][j])==st.end()) return 1;
     return 0;
  
  }
  if(i>=n or j>=m) return 0;
  if(st.find(grid[i][j])!=st.end()) return 0;
  //if(dp[i][j]!=-1) return dp[i][j];
  st.insert(grid[i][j]);
  
  int one = func(i,j+1,n,m,grid,st);
  int two = func(i+1,j,n,m,grid,st);
  st.erase(st.find(grid[i][j]));
  return one+two;
}
void solve(){
  int n,m; cin>>n>>m;
  vector<vector<int>> grid(n+1,vector<int>(m+1));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>grid[i][j];
    }
  }
  
	set<int> st;
 
  int ans=func(0,0,n,m,grid,st);
  
  cout<<ans<<"\n";
  
}
