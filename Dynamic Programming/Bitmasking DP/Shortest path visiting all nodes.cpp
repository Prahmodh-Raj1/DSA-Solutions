//Problem link: https://leetcode.com/problems/shortest-path-visiting-all-nodes/
//TC: O(N*N) SC: O(N*2^N)
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        //int mindist=INT_MAX;
        int n = graph.size();
       //Call bfs from  each node
       int allvisitedmask = (1<<n)-1;
       queue<pair<int,pair<int,int>>> q; //pair <curnode,pair<dist,mask>>
       set<pair<int,int>> seen; //<curnode,curmask as path>
       //Apply simultaneous bfs from all nodes
       for(int i=0;i<n;i++){
           q.push({i,{0,1<<i}}); //initially marking that node as visited
           seen.insert({i,1<<i}); //storing the path
       }
       while(!q.empty()){
           auto cur = q.front();
           q.pop();
           int node = cur.first;
           int curdist = cur.second.first;
           int pathmask = cur.second.second;
           //chk if all nodes are visited, When cuurent mask of current node will be allVisitedMask then we will stop
           if(pathmask == allvisitedmask) return curdist;

           //otherwise, visit all neighbours
           for(auto it:graph[node]){
               int nextPathMask = pathmask | (1<<it);
               //So, if we visit j-th node from i-th node then mask will be updated to = mask till i-th node | mask of j-th node
               if(!seen.count({it,nextPathMask})){
                   q.push({it,{curdist+1,nextPathMask}});
                   seen.insert({it,nextPathMask});
               }
           }
       }
       return 0;
    }
};
