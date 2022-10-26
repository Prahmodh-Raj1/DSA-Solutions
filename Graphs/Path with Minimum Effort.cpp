//Problem link: https://leetcode.com/problems/path-with-minimum-effort/
//TC : O(ElogV) SC :O(V)

class Solution {
public:
    bool isvalid(int r,int c,int m,int n){
        return (r>=0 and r<m and c>=0 and c<n);
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int r=heights.size();
        int c=heights[0].size();
        vector<vector<int>> dist(r,vector<int>(c,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});  //storing distance,{index-x,index-y} 
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        while(!pq.empty()){
            auto it=pq.top();
            int dif=it.first;
            int x=it.second.first;
            int y=it.second.second;
            pq.pop();
            if(x==r-1 and y==c-1){
                return dif;
            }
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(isvalid(nx,ny,r,c)){
                    int neweff=max(dif,abs(heights[nx][ny]-heights[x][y]));
                  
                    if(neweff < dist[nx][ny]){
                     
                        dist[nx][ny]=neweff;
                        pq.push({neweff,{nx,ny}});
                    }
                }
            }
        }
        return 0;
    }
};
