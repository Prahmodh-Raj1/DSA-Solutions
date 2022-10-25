//Problem link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//TC : O(V+E) SC: O(V+E)

bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        int cnt=0;
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
            //if(q.size()==0) return true;
        }
        if(cnt==V) return false;
        return true;
    }
