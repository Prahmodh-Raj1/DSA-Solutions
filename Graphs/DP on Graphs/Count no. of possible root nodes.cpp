//Problem link: https://leetcode.com/problems/count-number-of-possible-root-nodes/description/
//TC:O(N) SC:O(N)
class Solution {
public:
   
    map<pair<int,int>,int> dp;
    map<pair<int,int>,int> memguess;
    int dfs(vector<vector<int>>& adj,int node,int parent){
        if(dp.count({parent,node})){
            return dp[{parent,node}];
        }
        int res=memguess[{parent,node}];
        for(auto it:adj[node]){
            if(it!=parent){
                res+=dfs(adj,it,node);
            }
        }
        return dp[{parent,node}]=res;
    }
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n=edges.size();
        vector<vector<int>> adj(n+1);
        //Ref: https://leetcode.com/problems/count-number-of-possible-root-nodes/solutions/3256280/dynamic-programming-o-n-c/?orderBy=most_votes
        for(auto it:guesses){
            memguess[{it[0],it[1]}]=1;
        }
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans=0;
        for(int i=0;i<=n;i++){
            int chkguess=dfs(adj,i,-1);
            if(chkguess>=k) ans++;
        }
        return ans;
    }
};
