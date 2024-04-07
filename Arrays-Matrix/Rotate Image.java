//Problem link: https://leetcode.com/problems/rotate-image
//TC: O(N*N) SC: O(1)
class Solution {
    public void rotate(int[][] mat) {
        int n = mat.length;
        //Apply transpose then reverse each row
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int temp = mat[i][j];
                mat[i][j]=mat[j][i];
                mat[j][i]=temp;
            }
        }
        //Reversing each row
        for(int i=0;i<n;i++){
            int k=0,j=n-1;
            while(k<j){
                int temp = mat[i][k];
                mat[i][k] = mat[i][j];
                mat[i][j]=temp;
                k++;
                j--;
            }
        }
        return;
    }
}
