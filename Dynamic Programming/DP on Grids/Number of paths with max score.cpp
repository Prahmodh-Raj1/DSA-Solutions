//prob link: https://leetcode.com/problems/number-of-paths-with-max-score
//tc: o(n*n) sc: o(n*n)
class Solution {
public:
    int dir[3][2]={{0,-1},{-1,0},{-1,-1}};
    int mod=1000000007;
    int n;
    pair<int,int> dp[101][101];
    pair<int,int> max_sum(int i,int j,vector<string>& board)
    {
        if(i<0 || j<0 || board[i][j]=='X')
            return {INT_MIN,0};
        if(i==0 && j==0)
            return {0,1};
        if(dp[i][j].first!=-1)
            return dp[i][j];
        int val=board[i][j]=='S'?0:board[i][j]-'0';
        int res=INT_MIN,count=0;
        for(int k=0;k<3;k++)
        {
            pair<int,int> p=max_sum(i+dir[k][0],j+dir[k][1],board);
            if(p.first+val>res)
            {
                res=p.first+val;
                count=p.second;
            }
            else if(p.first+val==res)
                count=(count+p.second)%mod;
        }
        return dp[i][j]={res,count};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) 
    {
        n=board.size();
        for(int i=0;i<=100;i++)
            for(int j=0;j<=100;j++)
                dp[i][j]={-1,0};
        pair<int,int> p=max_sum(n-1,n-1,board);
        int sum=p.first;
        int paths=p.second;
        if(sum<0)
            return {0,0};
        return {sum,paths};
    }
};
