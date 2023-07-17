//Problem link: https://leetcode.com/problems/find-eventual-safe-states
//TC: O(N) SC: O(N)
class Solution {

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        vector<int> ans;
        int n=graph.size();
        vector<int> outdegree(n);
        vector<int> safe(n,0);
        queue<int> q;
        vector<vector<int>> adj(n);
        for(int j=0;j<n;j++){
            
            for(int i=0;i<graph[j].size();i++){
                adj[graph[j][i]].push_back(j);
                
            }
            outdegree[j]=graph[j].size();
            if(outdegree[j]==0) q.push(j);
            
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safe[node]=1;  //has zero outdegree
            for(auto it:adj[node]){
                if(--outdegree[it]==0){
                    q.push(it);
                } 
            }
        }
        for(int i=0;i<n;i++){
            if(safe[i]==1) ans.push_back(i);
        }
        return ans;
    }
};
//eXPLANATION: entual-safe-states/solutions/2600013/c-topological-sort-diagram/
