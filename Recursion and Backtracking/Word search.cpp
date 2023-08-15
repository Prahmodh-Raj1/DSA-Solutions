//prob link: https://leetcode.com/problems/word-search/
//TC: O(N*m*4^(len of word))
class Solution {
private:
    
    bool checkValid(int i,int j,vector<vector<char>>& board,string word,int k,int m,int n){
        if(k==word.size()) return true;
        if(i<0 || i>=m || j<0 || j>=n || board[i][j]=='.') return false;
        if(word.size()==1 && word[k]==board[i][j]) return true;
        if(word[k]!=board[i][j]) return false;
        board[i][j]='.';  //using it for now
        bool found=false;
        int dx[4] = {0,0,-1,1};
        int dy[4] = {-1,1,0,0};
        for(int l=0;l<4;l++){
            found = found | checkValid(i+dx[l],j+dy[l],board,word,k+1,m,n);
        }
        board[i][j] = word[k]; //returning the original value, backtracking step
        return found;
        
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n= board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(checkValid(i,j,board,word,0,m,n)) return true;
                }
            }
        }
        return false;
    }
};
