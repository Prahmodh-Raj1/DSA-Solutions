//Counting the number of possible ways to place n-queens in a nxn chessboard
#include<bits/stdc++.h>
using namespace std;
int n;
int queen[20]; //queen[i] tells where the queen is in row i
bool check(int row,int col){
	for(int i=0;i<row;i++){ //going through the previous rows
		int prevrow=i; //storing the previous queen's row
		int prevcol=queen[i]; //storing the previous queen's column
		if(pcol==col){  //can't place it in the same column
			return false;
		}
		if(abs(col-prevcol)==abs(row-prevrow)){ //chking for diagonals,if the difference between the rows is equal to the difference 
			//difference between the columns, then they are in the same diagonal
			return false;
		}

	}
	return true;
}
int nqueen(int level){  //nqueen is the number of ways to populate [level...n-1]rows for a valid configuration
	//level: row in which we are placing the queen
	if(level==n){  //basecase
		return 1;  //we've reached a valid solution
	}
	//compute
	int ans=0;
	//we loop over all choices
	for(int col=0;col<n;col++){
		if(check(level,col)){  //check if the choice is possible
			queen[level]=col; //it's possible to place a queen in that column in that level
			ans+=nqueen(level+1); //moving to the next level
			queen[level]=-1; //backtracking, revert placing the queen

		}
	}
	return ans;
}
int main(){
	cin>>n;
	memset(queen,-1,sizeof(queen)); //setting all the indices to -1 initially
	cout(rec(0));
}

//Problem link: https://leetcode.com/problems/n-queens/
class Solution {
public:
    int queen[20];
    bool check(int row,int col){
	for(int i=0;i<row;i++){ //going through the previous rows
		int prevrow=i; //storing the previous queen's row
		int prevcol=queen[i]; //storing the previous queen's column
		if(prevcol==col){  //can't place it in the same column
			return false;
		}
		if(abs(col-prevcol)==abs(row-prevrow)){ //chking for diagonals,if the difference between the rows is equal to the difference 
			//difference between the columns, then they are in the same diagonal
			return false;
		}

	}
	    return true;
}
void nqueen(int level,vector<vector<string>>& ans,int n){  //nqueen is the number of ways to populate [level...n-1]rows for a valid configuration
	//level: row in which we are placing the queen
	if(level==n){  //basecase
		
        vector<string> lvl;
        for(int i=0;i<n;i++){
            string te="";
            for(int i=0;i<n;i++){
                te+='.';
            }
            te[queen[i]]='Q';
            lvl.push_back(te);
        }
        ans.push_back(lvl);
        return;  //we've reached a valid solution
	}
	for(int col=0;col<n;col++){
		if(check(level,col)){  //check if the choice is possible
			queen[level]=col; //it's possible to place a queen in that column in that level
			nqueen(level+1,ans,n); //moving to the next level
			queen[level]=-1; //backtracking, revert placing the queen

		}
	}
	return;
}
    vector<vector<string>> solveNQueens(int n) {
       vector<vector<string>> ans;
        for(int i=0;i<n;i++) queen[i]=-1;
        nqueen(0,ans,n);
        return ans;
    }
    
};
