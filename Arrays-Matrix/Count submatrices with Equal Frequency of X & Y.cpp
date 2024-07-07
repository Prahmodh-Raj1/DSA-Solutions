//Problem link: https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/
//TC: O(M*N) Sc: O(2*M*N)
//Idea of Prefix sum on  matrices is applied
class Solution {
    vector<vector<int>> precompute(vector<vector<char>>& grid,char ch){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> cnt(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cnt[i][j] = (grid[i][j]==ch);
                //diagonalelements
                if(i>0 && j>0){
                    cnt[i][j]-=cnt[i-1][j-1]; //subtracting since the element at that position will repeat in the addition
                    //Refer 3:30 in this video for explanation:
                    //https://www.youtube.com/watch?v=auFt_ldukp0
                }
                if(i>0){
                    cnt[i][j]+=cnt[i-1][j];
                }
                if(j>0){
                    cnt[i][j]+=cnt[i][j-1];
                }
            }
        }
        return cnt;
    }
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        vector<vector<int>> x = precompute(grid,'X');
        vector<vector<int>> y  = precompute(grid,'Y');
        int cnt=0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(x[i][j]==y[i][j] && x[i][j]>0) cnt++;
            }
        }
        return cnt;
    }
};
