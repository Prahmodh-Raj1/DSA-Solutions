//Prob link: https://codeforces.com/problemset/problem/1106/D
//TC: O(N) Sc: O(N)
oid solve()
{
    ll n,m; cin>>n>>m;
    vector<vector<int>> adj(n+1);
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(1);
    vector<bool> vis(n+1,false);
    vis[1]=true;
    vector<int> val;
    while(!pq.empty()){
        int node = pq.top();
        cout<<node<<" ";
        pq.pop();
        //vis[node]=true;
        for(auto it:adj[node]){
            if(!vis[it]) {
                pq.push(it);
                vis[it]=true;
            }
        }
    }
    cout<<"\n";
}
