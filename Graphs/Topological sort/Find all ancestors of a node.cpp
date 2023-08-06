//Problem link: https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph
//TC: O(N*(N+E)logN) SC: O(N^2)
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n);
        //unordered_map<int,vector<int>> mp;
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
            //mp[it[1]].push_back(it[0]);
        }
        //vector<int> topo;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                //these nodes will have no ancestors
            } 
        }
        set<int> st[n]; //using set to get sorted unique ancestors
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            //topo.push_back(node);
            for(auto it:adj[node]){
                st[it].insert(node); //adding immediate parent
                for(auto i: st[node]){ //add all ancestores of the parent node
                    st[it].insert(i);
                }
                if(--indegree[it]==0){
                    q.push(it);
                }
            }
        }
        for(int i=0;i<n;i++){
            ans[i] = vector<int>(st[i].begin(),st[i].end());
        }
        return ans;

    }
};
