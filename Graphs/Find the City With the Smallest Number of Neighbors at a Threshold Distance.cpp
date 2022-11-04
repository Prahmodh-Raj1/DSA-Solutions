//Problem link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/
//TC:O(N^3)  SC:O(N^2)
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dist) {
        vector<vector<int>> v(n,vector<int>(n,1e9));
        
        
        for(auto it:edges){
            v[it[0]][it[1]]=it[2];
            v[it[1]][it[0]]=it[2];
        }
        
        for(int i=0;i<n;i++) v[i][i]=0;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
                }
            }
        }
        int city,mincnt=n+2;
        int cnt;
        
        for(int i=0;i<n;i++){
            cnt=0;
            for(int j=0;j<n;j++){
                if(v[i][j]<=dist){
                    cnt++;
                }
            }
            if(cnt<=mincnt){
                mincnt=cnt;
                city=i;
            }
        }
        return city;
    }
};
