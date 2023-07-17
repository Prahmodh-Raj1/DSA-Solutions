//Problem link: https://www.codingninjas.com/studio/problems/connecting-cities-with-minimum-cost_1386586?leftPanelTab=0
//TC: O(N*4*Alpha) SC: O(N)
#include <bits/stdc++.h> 
struct node{
	int u;
	int v;
	int wt;
	node(int _u,int _v,int _wt){
		u=_u;
		v=_v;
		wt=_wt;
	}
};
bool comp(node a, node b) {
    return a.wt < b.wt; 
}
int findPar(int u, vector<int> &parent) {
    if(u == parent[u]) return u; 
    return parent[u] = findPar(parent[u], parent); 
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findPar(u, parent);
    v = findPar(v, parent);
    if(rank[u] < rank[v]) {
    	parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
    	parent[v] = u; 
    }
    else {
    	parent[v] = u;
    	rank[u]++; 
    }
}
int getMinimumCost(int n, int m, vector<vector<int>> &connections)
{
	//	Write your code here.
	vector<node> edges;
	for(int i=0;i<m;i++){
		edges.push_back(node(connections[i][0],connections[i][1],connections[i][2]));
	}
	sort(edges.begin(),edges.end(),comp);
	vector<int> parent(n+1);
	for(int i=1;i<=n;i++){
		parent[i]=i;
	}
	vector<int> rank(n+1,0);
	int cost=0;
	
	for(auto it:edges){
		int findupar = findPar(it.u,parent);
		int findvpar = findPar(it.v,parent);
		if(findvpar!=findupar){
			unionn(it.u,it.v,parent,rank);
			cost+=it.wt;
		}
	}
	set<int> st;
	for(int i=1;i<=n;i++){
		st.insert(findPar(i,parent));
	}
	if(st.size()>1) return -1;
	return cost;

}
