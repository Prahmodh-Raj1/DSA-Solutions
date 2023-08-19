//Prob link: https://leetcode.com/problems/is-graph-bipartite
class Solution {
private:
    bool BipartiteCheck(vector<vector<int>>& adj,vector<int>& color,int node,int col){
        color[node]=col;
        for(auto it:adj[node]){
            if(color[it]==col) return false;
            else{//if color[it]==-1;
            
                if(BipartiteCheck(adj,color,it,!col)==false){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            int len = graph[i].size();
            for(int j=0;j<len;j++){
                adj[i].push_back(graph[i][j]);
                //adj[graph[i][j]].push_back(i);
            }
        }
        for(auto it:adj){
            for(auto i:it) cout<<i<<" ";
            cout<<"\n";
        }
        vector<int> color(n,0);
        queue<int> q;
        for(int i=0;i<n;i++){ //if there are more than 1 component
            if(color[i]) continue; //already colored
            color[i]=1;
            q.push(i);
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto it:adj[node]){
                    if(!color[it]){
                        //if uncolored
                        color[it] = -color[node];
                        q.push(it);
                    }else if(color[it]==color[node]) return false;
                }
            }
        }
        return true;

    }
};
