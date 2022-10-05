//Problem link: https://www.lintcode.com/problem/the-maze/description
//TC :O(N*M) SC:O(N*M)
class Solution {
public:
    
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        // write your code here
        int n=maze.size();
        int m=maze[0].size();
        queue<pair<int,int>> q;
        q.push({start[0],start[1]});     
        int vis[n][m];       
        memset(vis,0,sizeof(vis));         
        vis[start[0]][start[1]]=1;        
        while(!q.empty()){      
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(x==destination[0] && y==destination[1]) return true;
            int dx[]={-1,0,1,0};     
            int dy[]={0,1,0,-1};     
            for(int ind=0;ind<4;ind++){
                int newx=x;
                int newy=y;
                while(newx>=0 && newx<n && newy>=0 && newy<m && maze[newx][newy]==0){
                    newx+=dx[ind];
                    newy+=dy[ind];
                }
                
                newx-=dx[ind];
                newy-=dy[ind];     
                if(vis[newx][newy]==0){     
                    vis[newx][newy]=1;
                    q.push({newx,newy});
                }
            }            
                
        }
        return false;
    }

};
