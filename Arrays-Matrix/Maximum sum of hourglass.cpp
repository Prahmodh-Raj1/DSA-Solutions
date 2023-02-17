//Problem link: https://leetcode.com/problems/maximum-sum-of-an-hourglass/description/
//TC:O(N*M) SC:O(1)
class Solution {
public:
    bool inbounds(int i,int j,int m,int n){
        return i>=0 and i<m and j>=0 and j<n;
    }
    int maxSum(vector<vector<int>>& grid) {
        int maxi=-1;
        int m=grid.size();
        int n=grid[0].size();
        int dx[6]={0,0,1,2,2,2};
        int dy[6]={1,2,1,0,1,2};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                bool fl=true;
                int sum=grid[i][j];
                for(int k=0;k<6;k++){
                    int ni=i+dx[k];
                    int nj=j+dy[k];
                    
                    if(inbounds(ni,nj,m,n)){
                        sum+=grid[ni][nj];
                    }else{
                        fl=false;
                        break;
                    }
                }
                if(fl){
                    maxi=max(sum,maxi);
                }
            }
        }
        return maxi;
    }
};
