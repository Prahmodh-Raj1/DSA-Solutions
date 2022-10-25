//Problem link: https://leetcode.com/problems/find-eventual-safe-states/
//TC : O(VlogV + E) SC:O(V+E)

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //Reverse all the edges
        int n=graph.size();
        vector<int> indegree(n,0);
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                indegree[i]++;
                adj[it].push_back(i);
            }
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
              
              q.push(i);
            } 
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
