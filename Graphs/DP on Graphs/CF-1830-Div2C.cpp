//problem link: https://codeforces.com/contest/1830/problem/A
//Explanation; 
/*
This problem can be solved via dynamic programming. From here on out, step 1
 from the statement will be called a "scan".

Let dp[i]
 be the number of scans needed to activate node i
, and id[i]
 be the index (in the order from the input) of the edge which activated node i
.

Intially, since only 1 is active, dp[1]=1 and id[1]=0.

We will perform a dfs traversal starting from node 1
. When we process an edge (u,v), one of the following two cases can happen:

If index((u,v))≥id[u], we can visit vin the same scan as u:
  dp[v]=dp[u], id[v]=index((u,v))
If index((u,v))<id[u], v will be visited in the next scan after dp[u]:
dp[v]=dp[u]+1, id[v]=index((u,v))
The answer is max(dp[i])
.

Time complexity per test case: O(n)
*/
#include<bits/stdc++.h>

using namespace std;
const int NMAX = 2e5+5;
int dp[NMAX], id[NMAX];
vector<pair<int,int>> edg[NMAX];
void dfs(int u){
    for(auto it : edg[u]){
        if(dp[it.first] == 0){
            dp[it.first] = dp[u] + (it.second <= id[u]);
            id[it.first] = it.second;
            dfs(it.first);
        }
    }
}
void tc(){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) dp[i] = id[i] = 0, edg[i].clear();
    for(int i=1; i<n; i++){
        int u,v;
        cin>>u>>v;
        edg[u].push_back({v,i});
        edg[v].push_back({u,i});
    }
    dp[1] = 1;
    dfs(1);
    int ans = 0;
    for(int i=1; i<=n; i++) ans=max(ans,dp[i]);
    cout<<ans<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
        tc();
    return 0;
}
