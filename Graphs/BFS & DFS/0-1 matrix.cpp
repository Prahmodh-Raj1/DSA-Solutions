//Problem link: https://leetcode.com/problems/01-matrix
//TC: O(M*N) SC:O(1)
struct node{
    int i;
    int j;
    int dist;
    node(int _i,int _j,int dis){
        i=_i;
        j=_j;
        dist=dis;
    }
};
class Solution {
private:
    int dx[4]={0,-1,0,1};
    int dy[4]={-1,0,1,0};
    bool isValid(int i,int j,int m,int n){
        return i>=0 and i<m and j>=0 and j<n;
    }
    int bfs(int i,int j,vector<vector<int>>& mat,vector<vector<int>>& dp){
        queue<node> q;
        q.push(node(i,j,0));
        int n=mat[0].size();
        int m=mat.size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        while(!q.empty()){
            int x = q.front().i;
            int y = q.front().j;
            int steps = q.front().dist;
            q.pop();
            vis[x][y]=true;
            if(dp[x][y]!=-1){
                return steps+dp[x][y];
            }
            if(mat[x][y]==0){
                return steps;
            }
            for(int k=0;k<4;k++){
                int nx = x+dx[k];
                int ny = y+dy[k];
                if(isValid(nx,ny,m,n) and !vis[nx][ny]){
                    q.push(node(nx,ny,steps+1));
                }
            }
        }
        return 0;
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int maxi=m+n;
        //vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){  //going from top to bottom , left to right
        //value is calculated from left and top neighbours
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    continue;
                }
                int topneighbour = m+n;
                int leftneighbour=m+n;
                if(i-1>=0) topneighbour = mat[i-1][j];
                if(j-1>=0) leftneighbour= mat[i][j-1];
                mat[i][j]=min(topneighbour,leftneighbour)+1;
            }
        }
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(mat[i][j]==0) continue;
                int bottomneighbour = m+n;
                int rightneighbour = m+n;
                if(i+1<m) bottomneighbour = mat[i+1][j];
                if(j+1<n) rightneighbour = mat[i][j+1];
                mat[i][j] = min(mat[i][j],min(bottomneighbour,rightneighbour)+1);
            }
        }
        return mat;
    }
};
//Explanation: https://leetcode.com/problems/01-matrix/solutions/1369741/c-java-python-bfs-dp-solutions-with-picture-clean-concise-o-1-space/
