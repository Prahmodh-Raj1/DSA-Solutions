//Problem link: https://cses.fi/problemset/task/1674/
//TC:O(N) SC:O(N)

#include<bits/stdc++.h>
using namespace std;
#define  nfs       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);

vector<int> adj[300001];
void dfs(int node,vector<bool>& vis,vector<int>& ans){
	int res=0;
	vis[node]=true;
	for(auto it:adj[node]){
		if(!vis[it]){
			dfs(it,vis,ans);
			res+=1+ans[it];  //no. of nodes from that point , which are subordinates
		}
	}
	ans[node]=res;
	
}
int main(){

	nfs;
	#ifndef ONLINE_JUDGE
    	freopen("input.txt","r",stdin);
    	freopen("output.txt","w",stdout);
    	#endif
	int n;
	cin>>n;
	vector<int> v(n-1);
	for(int i=0;i<n-1;i++){
		int x;
		cin>>x;
		adj[x].push_back(i+2);
	} 
	vector<bool> vis(n+1,false); 
	vector<int> ans(n+1,0);
	//ans[1]=n-1;
	dfs(1,vis,ans);
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}

}
