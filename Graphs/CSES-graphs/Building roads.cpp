//Problem link: https://cses.fi/problemset/task/1666/
#include<bits/stdc++.h>
 
using namespace std;
 
#define  nfs       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define  f              first
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()
int find(int x,vector<int>& parent){
	if(parent[x]==x) return x;
	else return parent[x]=find(parent[x],parent);  //path compression
}

void unite(int x,int y,vector<int>& parent,vector<int>& ranks){
	x=find(x,parent); //finding the root node of x
	y=find(y,parent); //finding the root nod of y
	if(ranks[x]>ranks[y]){
		parent[y]=x;
	}
	else if(ranks[y]>ranks[x]){
		parent[x]=y;
	}
	else{
		parent[y]=x;
		ranks[x]++;
	}
}

void solve()
{
    int n,m; cin>>n>>m;
    vector<vector<int>> adj(n+1);
    int u,v;
    vector<int> parent(n+1,0);
    vector<int> ranks(n+1,0);
    for(int i=1;i<=n;i++) parent[i]=i;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
        unite(u,v,parent,ranks);
    }
    set<int> st;
    for(int i=1;i<=n;i++){
        st.insert(find(i,parent));
    }
    cout<<st.size()-1<<"\n";
    if(st.size()==1){
        return;
    }
    vector<int> temp;
    for(auto it:st) temp.pb(it);
    for(int i=0;i<temp.size()-1;i++){
        cout<<temp[i]<<" "<<temp[i+1]<<"\n";
    }
    
    
}
int main(){
	solve();
	return 0;
}
