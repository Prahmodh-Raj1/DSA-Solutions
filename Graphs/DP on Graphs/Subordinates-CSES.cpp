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

//Detailed solution:
#include<bits/stdc++.h>
using namespace std;

bool isLeaf(int node,vector<vector<int>>& adj){
	if(node!=1 && adj[node].size()==1) return true;
	return false;
}
void dfs(int node,int parent,vector<vector<int>>& adj,vector<int>& dp){
	if(isLeaf(node,adj)){
		dp[node]=1;
		return;
	}
	
	
	//Perform the DP on trees in two stages
	for(auto it:adj[node]){  //Dp values for each child is being found
		if(it==parent) continue;
		
		dfs(it,node,adj,dp);
		
	}

	for(auto it:adj[node]){ //computing the dp values for each node
		if(it==parent) continue;
		dp[node] += dp[it];
	}
	dp[node]++; //considering itself
	
}
int main(){
	int n; cin>>n;
	vector<vector<int>> adj(n+1);
	int parent;
	for(int i=2;i<=n;i++){ //creating an undirected graph
		cin>>parent;
		adj[parent].push_back(i);
		adj[i].push_back(parent);
	}
	vector<int> dp(n+1,0);
	//vector<int> vis(n+1,0);
	//vis[1]=1;
	dfs(1,-1,adj,dp);
	for(int i=1;i<=n;i++){
		cout<<dp[i]-1<<" ";
	}
	return 0;

}
