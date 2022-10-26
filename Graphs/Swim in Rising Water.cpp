//Problem link:https://leetcode.com/problems/swim-in-rising-water/
//TC : O(N^2logN)  SC : O(N*N)
class Solution {
public:
    bool isvalid(int r,int c,int m,int n){
        return (r>=0 and r<m and c>=0 and c<n);
    }
    int swimInWater(vector<vector<int>>& grid) {
       int n=grid.size();
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        int time=0;
        vector<vector<int>> vis(n,vector<int>(n,0));
        vis[0][0]=1;
        pq.push({grid[0][0],{0,0}});
        //we are using priority queue , so if some child cell is already visited , then that means its value is already in the priority queue
        //and if that cell leads a better path then it will become the top of the queue automatically after we pop our current parent cell
        //and our final res wont be affected as it is res = max(res, p.t); i.e. max water level required to float
        while(!pq.empty()){
            auto it=pq.top();
            int elev=it.first;
            int r=it.second.first;
            int c=it.second.second;
            pq.pop();
            time=max(time,elev);
            if(r==n-1 and c==n-1) return time;
            for(int i=0;i<4;i++){
                int nr=dx[i]+r;
                int nc=dy[i]+c;
                if(isvalid(nr,nc,n,n) and !vis[nr][nc]){
                    vis[nr][nc]=1;
                    pq.push({grid[nr][nc],{nr,nc}});
                    
                }
            }
            
        }
        return time;
    }
};
