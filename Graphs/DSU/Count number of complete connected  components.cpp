//Problem link: https://leetcode.com/problems/count-the-number-of-complete-components/
//TC: O(max(n, len(edges))) SC: O(N)
//Explanation: https://leetcode.com/problems/count-the-number-of-complete-components/solutions/3521878/c-java-python3-union-find-with-count/
class DSU {
private:
    vector<int> p, rank, count;
public:
    DSU(int n) {
        p.resize(n), rank.resize(n), count.resize(n, 1);
        for (int i = 0; i < n; ++i) p[i] = i;
    }
    int find(int x) {
        if (x != p[x]) p[x] = find(p[x]);
        return p[x];
    }
    void union_set(int x, int y) {
        int xx = find(x), yy = find(y);
        if (xx == yy) return;
        count[xx] = count[yy] = count[xx] + count[yy];
        if (rank[xx] < rank[yy]) p[xx] = yy;
        else p[yy] = xx;
        if (rank[xx] == rank[yy]) ++rank[xx];
    }
    int sizeOfGroupThatXIsAPartOf(int x) {
        return count[find(x)];
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU uf(n);
        set<int> groups;
        vector<int> counter(n, 0);
        for (auto& e : edges) {
            uf.union_set(e[0], e[1]);
            ++counter[e[0]], ++counter[e[1]];
        }
        
        for (int i = 0; i < n; ++i)
            groups.insert(uf.find(i));

        for (int i = 0; i < n; ++i)
            if (uf.sizeOfGroupThatXIsAPartOf(i) != counter[i] + 1) 
                groups.erase(uf.find(i));

        return groups.size();
    }
};

//Using DFS
class Solution {
private:
    vector<int> pathnodes;
    void dfs(vector<vector<int>>& adj,vector<bool>& vis,int node){
        vis[node]=true;
        pathnodes.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(adj,vis,it);
            }
        }
    }
    
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n,false);
        set<pair<int,int>> st;
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            st.insert({it[0],it[1]});
            st.insert({it[1],it[0]});
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                pathnodes.clear();
                dfs(adj,vis,i);
                //check if each pair of nodes have an edge between them
                int size = pathnodes.size();
                bool fl=true;
                for(int i=0;i<size;i++){
                    int node = pathnodes[i];
                    
                    for(int j=i+1;j<size;j++){
                        pair<int,int> edge = make_pair(node,pathnodes[j]);
                        if(st.find(edge)==st.end()){
                            fl=!fl;
                            break;
                        }
                    }
                    if(!fl) break;
                }
                if(fl) cnt++;
            }
            
        }
        return cnt;
    }
};
