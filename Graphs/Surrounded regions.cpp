//Problem link: https://leetcode.com/problems/surrounded-regions/
//TC :O(M*N) SC:O(M*N)
class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    bool vis[200][200];
    bool isvalid(int i,int j,int n,int m){
        return i>=0 and i<m and j>=0 and j<n;
    }
    void dfs(int i,int j,vector<vector<char>>& board){
        
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(isvalid(nr,nc,board[0].size(),board.size())){

                if(board[nr][nc]=='O' and !vis[nr][nc]){
                    vis[nr][nc]=true;
                    dfs(nr,nc,board);
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        memset(vis,false,sizeof(vis));
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            if(board[i][0]=='O' and !vis[i][0]){
                vis[i][0]=true;
                dfs(i,0,board);
            }
            else if(board[i][n-1]=='O' and !vis[i][0]){
                vis[i][n-1]=true;
                dfs(i,n-1,board);
            }
        }
        for(int j=0;j<n;j++){
            if(board[0][j]=='O' and !vis[0][j]){
                vis[0][j]=true;
                dfs(0,j,board);
            }
            else if(board[m-1][j]=='O' and !vis[m-1][j]){
                vis[m-1][j]=true;
                dfs(m-1,j,board);
            }
        }
           
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j] == false and board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        
    }
};
