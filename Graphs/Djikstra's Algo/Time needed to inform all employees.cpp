//Problem link: https://leetcode.com/problems/time-needed-to-inform-all-employees
//TC: O(ElogV)  SC: O(E*V)
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<pair<int,int>>> adj(n);
        int src=headID;
        int timeManager = informTime[src];
        for(int i=0;i<n;i++){
            if(manager[i]==headID){
                adj[headID].push_back({i,timeManager});
            }else if(manager[i]!=-1){
                adj[manager[i]].push_back({i,informTime[manager[i]]});
            }
        }
        for(auto it:adj){
            for(auto i:it){
                cout<<i.first<<" "<<i.second<<"\n";
            }
        }
        vector<int>dis(n,1e9+10);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        dis[src]=0;
        vector<int>vis(n+10,0);
        while(pq.size())
        {
            auto [wt,node]=pq.top();
            pq.pop();
            if(vis[node])
            {
                continue;
            }
            vis[node]=1;
            for(auto &[current_node,current_wt]:adj[node])
            {
                if(dis[current_node]>current_wt+wt)
                {
                    dis[current_node]=current_wt+wt;
                    pq.push({dis[current_node],current_node});
                }
            }
        }
        int maxi=-1;
        for(int i=0;i<n;i++){
            if(dis[i]!=1e9+10){
                maxi=max(maxi,dis[i]);
            }
        }
        return maxi;
    }
};
