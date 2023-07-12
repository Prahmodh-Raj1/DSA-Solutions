//Problem link: https://atcoder.jp/contests/abc211/tasks/abc211_d
//TC: O(E+V) SC: O(V)
//Refer notebook for explanation
//Video explanation: https://www.youtube.com/watch?v=8HLGOX0cjYQ
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
#define INT_SIZE 32
 
typedef  long long             ll;
typedef  long double           ld;
 
const ll   N     =  1e3 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
void solve(){
  int n,m; cin>>n>>m;
  vector<vector<int>> adj(n+1);
  int u,v;
  for(int i=0;i<m;i++){
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> dist(n+1,1e9);
  vector<int> numberofshortestpaths(n+1,0);
  dist[1]=0;
  numberofshortestpaths[1]=1; //there's always one path to reach the node itself
  queue<int> q;
  q.push(1);
  while(!q.empty()){
   	int node = q.front();
    q.pop();
    for(auto it:adj[node]){  
     	if(dist[it]>dist[node]+1){
          //we know all shortest paths must go through node and reach it
         	dist[it]=dist[node]+1;
          	numberofshortestpaths[it]=numberofshortestpaths[node];
          	q.push(it);
        }else if(dist[it]==dist[node]+1){
          //we know that numberofshortestpaths[node] are there which go through node and then reach it
          //and we have not considered them yet 
          numberofshortestpaths[it]=(numberofshortestpaths[it]+numberofshortestpaths[node])%mod;
        }
    }
  }
  cout<<numberofshortestpaths[n]<<"\n";
  
}

int main() {
	
	nfs;
	#ifndef ONLINE_JUDGE
    	freopen("input.txt","r",stdin);
    	freopen("output.txt","w",stdout);
    	#endif
    cout << setprecision(10);
    
   solve();
    
	return 0;
}
