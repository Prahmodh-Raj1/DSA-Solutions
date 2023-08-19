//Prob link: https://www.codingninjas.com/studio/problems/detect-cycle-in-a-directed-graph-_920545?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1
#include<bits/stdc++.h>
bool dfs(vector<vector<int>>& adj,int node,vector<bool>& vis,vector<bool>& curpath){
	vis[node]=true;
	curpath[node]=true;
	for(auto it:adj[node]){
		if(!vis[it] and !curpath[it]){
			if(dfs(adj,it,vis,curpath)==true) return true;
		}else if(curpath[it]){
			return true;
		}
	}
	curpath[node]=false;
	return false;
}
bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	// Write your code here
	vector<vector<int>> adj(v);
	for(auto it:edges){
		adj[it[0]].push_back(it[1]);
	}
	vector<bool> vis(v,false),curpath(v,false);
	for(int i=0;i<v;i++){
		if(!vis[i]){
			if(dfs(adj,i,vis,curpath)==true){
				return true;
			}
		}
	}
	return false;
}
