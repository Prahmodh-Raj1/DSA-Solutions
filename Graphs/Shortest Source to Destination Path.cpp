//Problem link: https://practice.geeksforgeeks.org/problems/shortest-source-to-destination-path3544/1
//TC :O(N*M) SC:O(N*M)
class Solution {
  public:
    struct node{
    int x,y,cost;
    node(int _x,int _y,int _cost){        //creating a constructor
        x=_x;
        y=_y;
        cost=_cost;
    }
    }; 
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if(A[0][0]==0) return -1;
        queue<node> q;
        q.push(node(0,0,0));
        const int dx[4] = {0, 0, 1, -1};
        const int dy[4] = {1, -1, 0, 0};
        bool visited[N][M];
        memset(visited,false,sizeof(visited));
        visited[0][0]=true;
        while(!q.empty()){
            int x=q.front().x;
            int y=q.front().y;
            int cost=q.front().cost;
            q.pop();
            if(x==X and y==Y) return cost; 
            for(int i=0;i<4;i++){
                int newx=x+dx[i];
                int newy=y+dy[i];
                if(newx>=0 and newy>=0 and newx<N and newy<M and A[newx][newy]==1 and visited[newx][newy]==false){
                    q.push(node(newx,newy,cost+1));
                    visited[newx][newy]=true;
                }
            }
        }
        return -1;
    }
};
