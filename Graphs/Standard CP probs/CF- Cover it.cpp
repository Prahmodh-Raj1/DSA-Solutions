//Problem link: https://codeforces.com/problemset/problem/1176/E
//TC: O(N) SC: O(2*N)

/*Firstly, let's run bfs on the given graph and calculate distances for all vertices. In fact, we don't need distances, we need their parities.
  The second part is to find all vertices with an even distance, all vertices with and
odd distance, and print the smallest by size part. Why is it always true? Firstly, it is obvious that at least one of these sizes will not exceed ⌊n/2⌋
. And secondly, because we are checking just parities of distances, it is obvious that each vertex of some parity is 
connected with at least one vertex of the opposite parity (because it has this parity from some vertex of the opposite parity).*/
void solve()
{
    ll n,m; cin>>n>>m;
    vector<vector<ll>> edges(n+1);
    vector<ll> degree(n+1,0);
    for (int i=1;i<=m;i++) {
        ll u,v;
        cin>>u>>v;
        edges[u].pb(v);
        edges[v].pb(u);
        degree[u]++;
        degree[v]++;
    }
    vector<int> col(n+1,-1);
    
    queue<pair<ll,int>> q;
   
    for (ll i = 1; i <= n; i++) {
       
      //if not coloured
        if (col[i] == -1) {
           
          //colouring with 0 i.e. red
            q.push({ i, 0 });
            col[i] = 0;
           
            while (!q.empty()) {
                pair<ll, int> p = q.front();
                q.pop();
               
                  //current vertex
                ll v = p.first;
                  //colour of current vertex
                int c = p.second;
                 
                  //traversing vertexes connected to current vertex
                for (auto j : edges[v]) {
                   
                      //if already coloured with parent vertex color
                      //then bipartite graph is not possible
                    
                      //if uncoloured
                    if (col[j] == -1) {
                      //colouring with opposite color to that of parent
                        col[j] = (c) ? 0 : 1;
                        q.push({ j, col[j] });
                    }
                }
            }
        }
    }
    vector<int> even,odd;
    for(int i=1;i<=n;i++){
        if(col[i] & 1){
            odd.pb(i);
        }else even.pb(i);
    }
    if(odd.size()<=even.size()){
        cout<<odd.size()<<"\n";
        for(auto it:odd) cout<<it<<" ";
        cout<<"\n";
    }
    else{
        cout<<even.size()<<"\n";
        for(auto it:even) cout<<it<<" ";
        cout<<"\n";
    }
    
    return;
}
