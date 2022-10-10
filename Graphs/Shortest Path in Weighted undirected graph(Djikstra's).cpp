//Problem link: https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-weighted-undirected-graph
class Solution{
    public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n+1];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int> parent(n+1);
        vector<int> dist(n+1,1e9);
        dist[1]=0;
        for(int i=1;i<=n;i++) parent[i]=i;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({1,0});
        while(!pq.empty()){
            int ele=pq.top().first;
            int curdist=pq.top().second;
            pq.pop();
            for(auto it:adj[ele]){
                int edwt = it.second;
                int curnode=it.first;
                if(curdist+edwt<dist[curnode]){
                    dist[curnode]=curdist+edwt;
                    pq.push({curnode,dist[curnode]});
                    parent[curnode]=ele;
                }
            }
        }
        if(dist[n]==1e9) return {-1};
        vector<int> path;
        int node=n;
        while(parent[node]!=node){
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        return path;
    }
};
