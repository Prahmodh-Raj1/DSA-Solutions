

//Memoization
int dp[101][101][101];
int dj[3]={-1,0,1}; //possible motions from one point
    int func(int i,int j1,int j2,vector<vector<int>>& grid){  //TC :O(N*M*M*9) SC:O(N*M*M)+O(Stack space)
        if(j1<0 or j1>=grid[0].size() or j2<0 or j2>=grid[0].size()){
            return -1000; //returning a negative value if we have gone out of bounds
        }
        if(i==grid.size()-1){ 
            if(j1==j2){
                return grid[i][j1];
            }
            return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int maxi=-1;
        for(int d1=0;d1<3;d1++){
            for(int d2=0;d2<3;d2++){
                if(j1==j2){
                    maxi=max(maxi,grid[i][j1]+func(i+1,j1+dj[d1],j2+dj[d2],grid));
                }else{
                    maxi=max(maxi,grid[i][j1]+grid[i][j2]+func(i+1,j1+dj[d1],j2+dj[d2],grid));
                }
            }
        }
        return dp[i][j1][j2]=maxi;
       
    }

//Tabulation
   int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dp[n][m][m];
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                if(j1==j2){
                    dp[n-1][j1][j2]=grid[n-1][j1];
                }else{
                    dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
                }
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int j1=0;j1<m;j1++){
                for(int j2=0;j2<m;j2++){
                            int maxi=-1e8;
                            for(int d1=0;d1<3;d1++){
                                for(int d2=0;d2<3;d2++){
                                    int val=0;
                                    if(j1==j2){
                                        val=grid[i][j1];
                                    }else{
                                        val=grid[i][j1]+grid[i][j2];
                                    }

                                    if(j1+dj[d1]>=0 and j1+dj[d1]<m and j2+dj[d2]>=0 and j2+dj[d2]<m){
                                        val+=dp[i+1][j1+dj[d1]][j2+dj[d2]];
                                    }else{
                                        val+=-1e8;
                                    }
                                    maxi=max(val,maxi);
                                }
                            }
                            dp[i][j1][j2]=maxi;
                }
            }
        }
        return dp[0][0][m-1];
    }

//Space Optmization
//SC: O(N^2)
  int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //int dp[n][m][m];
        vector < vector < int >> front(m, vector < int > (m, 0)), cur(m, vector < int > 
  (m, 0));
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                if(j1==j2){
                    front[j1][j2]=grid[n-1][j1];
                }else{
                    front[j1][j2]=grid[n-1][j1]+grid[n-1][j2];
                }
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int j1=0;j1<m;j1++){
                for(int j2=0;j2<m;j2++){
                            int maxi=-1e8;
                            for(int d1=0;d1<3;d1++){
                                for(int d2=0;d2<3;d2++){
                                    int val=0;
                                    if(j1==j2){
                                        val=grid[i][j1];
                                    }else{
                                        val=grid[i][j1]+grid[i][j2];
                                    }

                                    if(j1+dj[d1]>=0 and j1+dj[d1]<m and j2+dj[d2]>=0 and j2+dj[d2]<m){
                                        val+=front[j1+dj[d1]][j2+dj[d2]];
                                    }else{
                                        val+=-1e8;
                                    }
                                    maxi=max(val,maxi);
                                }
                            }
                            cur[j1][j2]=maxi;
                }
            }
            front=cur;
        }
        return front[0][m-1];
    }
