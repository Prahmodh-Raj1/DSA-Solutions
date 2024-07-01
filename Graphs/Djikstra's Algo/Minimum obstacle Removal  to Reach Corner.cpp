//Problem Link: https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/
//TC: O(M*N) SC: O(M*N)

class Solution {
private:
    bool isValid(int r,int c,int m,int n){
        return r>=0 and r<m and c>=0 and c<n;
    }
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> dis(r,vector<int>(c,1e9));
        dis[0][0]=0;
        pq.push({0,{0,0}});
        int dx[]  = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        while(!pq.empty()){
            auto it = pq.top();
            int dif = it.first;
            int x= it.second.first;
            int y = it.second.second;
            if(x==r-1 and y==c-1) return dif;
            pq.pop();
            /*
            dist[i][j] to indicate the currently minimum obstacles need to remove to reach (i, j);
            Applying Djikstra
            */
            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(isValid(nx,ny,r,c) and dif+grid[nx][ny]<dis[nx][ny]){
                    dis[nx][ny] = dif+grid[nx][ny];
                    
                    pq.push({dis[nx][ny],{nx,ny}});
                    
                }
            }
        }
        return dis[r-1][c-1];
    }
};
