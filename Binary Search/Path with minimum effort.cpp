//problem link: https://leetcode.com/problems/path-with-minimum-effort/
//TC: O(M*N*log(Maxi)) SC: O(log(Maxi)(M*N))
class Solution {
public:
    bool boundary(int i,int j,int m,int n){
        return (i>=0 and i<m and j>=0 and j<n);
    }
    bool check(vector<vector<int>>& heights,long long mid){
        long long maxi=0;
        int m=heights.size();
        int n=heights[0].size();
        int di[4]={0,-1,0,1};
        int dj[4]={-1,0,1,0};
        vector<vector<bool>> visited(101,vector<bool>(101,false));
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
           // int cur=q.front().first;
            q.pop();
            
            if(i==m-1 and j==n-1){
                return true;
            }
            for(int x=0;x<4;x++){
                int ni = i + di[x];
                int nj = j+dj[x];
                if(boundary(ni,nj,m,n) and !visited[ni][nj] and abs(heights[ni][nj]-heights[i][j])<=mid){
                    visited[ni][nj]=true;
                    q.push({ni,nj});
                }
            }

        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int low=0;
        int high=0;
        for(auto it:heights){
            for(auto i:it) high=max(high,i);
        }
        while(low<high){
            int mid = (low+high)/2;
            if(check(heights,mid)){
                high=mid;
            }else low=mid+1;
        }
        return low;
    }
};
