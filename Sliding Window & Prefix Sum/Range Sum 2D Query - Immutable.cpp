//Problem link: https://leetcode.com/problems/range-sum-query-2d-immutable/
//TC: O(M*N) SC:O(M*N)
class NumMatrix {
public:
    vector<vector<int>> pref;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n= matrix[0].size();
        pref.resize(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            pref[0][i] = matrix[0][i];
        }
        //adding column  wise
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                pref[i][j] = pref[i-1][j]+matrix[i][j];
            }
        }

        //adding row-wise
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                pref[i][j]+=pref[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int temp=pref[row2][col2];  // temp is now sum of elements between (0, 0) and
    // (ri, rj)
	    if(row1>0) temp-=pref[row1-1][col2]; // // Remove elements between (0, 0) and (li-1, rj)
	    if(col1>0) temp-=pref[row2][col1-1];  // Remove elements between (0, 0) and (ri, lj-1)
	    if(row1>0 and col1>0) temp+=pref[row1-1][col1-1];
        return temp;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
