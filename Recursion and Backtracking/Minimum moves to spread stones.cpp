//Prob link: https://leetcode.com/problems/minimum-moves-to-spread-stones-over-grid
//TC: O((3 ^n) * (N^2))  SC: O(Max depth of Recursion)
class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int zeroes=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]==0){
                    zeroes++;
                }
            }
        }
        //Each time we encounter a cell with grid[i][j] == 0 then we can take 1 from any of the other 8 cells which have a value > 1
        if(zeroes==0) return 0;
        int ans=INT_MAX;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]==0){
                    //try to take a cell with val>1 and bring it to cell with zero

                    for(int x=0;x<3;x++){
                        for(int y=0;y<3;y++){
                            int dist = abs(x-i) + abs(y-j);
                            if(grid[x][y]>1){
                                //movement is possible from this cell
                                grid[x][y]--;
                                grid[i][j]++;
                                ans = min(ans,dist + minimumMoves(grid)); //make recursive calls until all the cells have one stone in them
                                grid[x][y]++; //backtracking phase
                                grid[i][j]--;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
