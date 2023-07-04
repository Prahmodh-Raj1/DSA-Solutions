//prob link: https://codeforces.com/problemset/problem/1520/D
//TC: O(N) SC: O(N)
void solve()
{
    ll n; cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    unordered_map<int,int> mp;
    ll ans=0;
    for(int i=0;i<n;i++){
        int dif = v[i]-i;
        if(mp.find(dif)!=mp.end()){
            ans+=mp[dif];
        }
        mp[dif]++;
    }
    cout<<ans<<"\n";
    
    
}
