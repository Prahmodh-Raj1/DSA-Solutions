//Problem link: https://codeforces.com/problemset/problem/1352/C
//TC: O(log(1e14)) SC: O(1)
bool checkdiv(ll mid,ll k,ll n){
    ll val = mid - mid/n;
    return val>=k;
}
void solve()
{
    ll n,k; cin>>n>>k;
    ll low=1,high=1e14;
    while(low<high){
        ll mid = (low+high)/2;
        if(checkdiv(mid,k,n)) high=mid;
        else low=mid+1;
    }
    cout<<low<<"\n";
    
}
