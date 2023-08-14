//Prob link: https://leetcode.com/problems/search-a-2d-matrix
//TC: O(log(M*N)) SC: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0;
        int col = n-1;
        while(row<m && col>=0){
            if(matrix[row][col]==target) return true;
            if(matrix[row][col]<target){
                //we need to move to the next row
                row++;
            }else{ //if target is smaller
                //we need to move to the previous column
                col--;
            }
        }
        return false;
    }
};
