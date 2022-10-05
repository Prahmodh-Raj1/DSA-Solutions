//Problem link: https://leetcode.com/problems/rotting-oranges/
//TC :O(M*N) SC:O(No. of Oranges)

#include<bits/stdc++.h>
struct node{
    int x,y,time;
    node(int _x,int _y,int _time){        
        x=_x;
        y=_y;
        time=_time;
    }
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        queue<node> q;
        int cntorange=0;
        //push the rotten oranges
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push(node(i,j,0));     
                }
                if(grid[i][j]!=0) cntorange++;
            }
        }
        int ans=0;
        int cnt=0;       
        while(!q.empty()){
            int x = q.front().x;
            int y = q.front().y;
            int time = q.front().time;
            q.pop();
            ans=max(ans,time);
            cnt++;
            
            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};
            for(int ind=0;ind<4;ind++){
                int newx=x+dx[ind];
                int newy=y+dy[ind];
                if(newx>=0 && newx<n && newy>=0 && newy<m && grid[newx][newy]==1){ 
                    grid[newx][newy]=2;
                    q.push(node(newx,newy,time+1));
                } 
            }
        }
        if(cnt==cntorange) return ans;
        return -1;
    }
};
