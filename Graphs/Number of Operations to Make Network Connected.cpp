//Problem link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/
class Solution {
public:
    int findpar(int u,vector<int>& parent){
        if(u==parent[u]) return u;
        return parent[u]=findpar(parent[u],parent);
    }
    void unionn(int u,int v,vector<int>& parent){
        u=findpar(u,parent);
        v=findpar(v,parent);
        if(u!=v){
            parent[v]=u;
        }
    }
    bool sameset(int u,int v,vector<int>& parent){
        u=findpar(u,parent);
        v=findpar(v,parent);
        if(u==v) return true;
        return false;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> parent(n);
        int nl=connections.size();
        for(int i=0;i<n;i++) parent[i]=i;
        int extra=0; //contains all the extra edges, on the removal of which the component is still connected
        for(int i=0;i<nl;i++){
            if(sameset(connections[i][0],connections[i][1],parent)){
                extra++;
            }else{
                unionn(connections[i][0],connections[i][1],parent);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
            if(parent[i]==i) cnt++;
        if(extra>=cnt-1) return cnt-1;
        return -1;
    }
};
