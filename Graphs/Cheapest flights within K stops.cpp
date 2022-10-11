//Problem link: https://leetcode.com/problems/cheapest-flights-within-k-stops/
//TC :O(E) SC :O(N)
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<pair<int,int>> adj[n];
        int m=flights.size();
        for(int i=0;i<m;i++){
            int temp=flights[i][0];
            adj[temp].push_back({flights[i][1],flights[i][2]});
        }
        vector<int> stops(n,-1);
        stops[src]=0;
        vector<int> dist(n+1,1e9);
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        dist[src]=0;
        while(!q.empty()){
            int node=q.front().second.first;
            int dis=q.front().second.second;
            int stop=q.front().first;
            q.pop();
            if(stop>k) continue;
            for(auto it:adj[node]){
                int edw=it.second;
                int cur=it.first;
                if(stop<=k){
                    if(edw+dis<dist[cur]){
                        dist[cur]=edw+dis;
                        q.push({stop+1,{cur,dist[cur]}});
                    }
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};
