//prob link: https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/description/
//TC: O(NlogN) SC: O(2*N)
class DSU{

public:

    vector<int> parent,sizer;
    DSU(int n){
        parent.resize(n+1);
        sizer.resize(n+1,1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
    }
    int find(int x){
	    if(parent[x]==x) return x;
	    else return parent[x]=find(parent[x]);  //path compression
    }
    
    void unite(int x,int y){
	x=find(x); //finding the root node of x
	y=find(y); //finding the root nod of y
	if(sizer[x]>sizer[y]){
		parent[y]=x;
		sizer[x]+=sizer[y];
	}
	else if(sizer[y]>sizer[x]){
		parent[x]=y;
		sizer[y]+=sizer[x];
	}
	else{
		parent[y]=x;
		sizer[x]+=sizer[y];
	}
}
};
class Solution {
public:
    static bool comp(vector<int>& v1,vector<int>& v2){
        return v1[0]<v2[0];
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU dsa(n);
        DSU dsb(n);
        //keep two dsu's, one for alice and the other for bob.
        //Apply dsu by size as we need to assemble the nodes based on the size of the component
        //Keep all the Type 3 edges
        //Traverse through the rest of the edges of type1 and type2 and if both are in the same component, then we can skip that edge, no otherwise
        //finally check the size of both the dsu's, they need to equal n
        int cnt=0;
        //sort(edges.begin(),edges.end(),comp);
        for(auto it:edges){
            if(it[0]==3){
                bool fl=false;
                if(dsa.find(it[1])!=dsa.find(it[2])){
                    fl=true;
                    dsa.unite(it[1],it[2]);
                }
                if(dsb.find(it[1])!=dsb.find(it[2])){
                    fl=true;
                    dsb.unite(it[1],it[2]);
                }
                if(!fl){
                    cnt++;
                }
            }
        }
        for(auto it:edges){
            
            if(it[0]==1){
                if(dsa.find(it[1])!=dsa.find(it[2])){
                    dsa.unite(it[1],it[2]);
                }else cnt++;
            }
            else if(it[0]==2){
                if(dsb.find(it[1])!=dsb.find(it[2])){
                    dsb.unite(it[1],it[2]);
                }else cnt++;
            }

        }
        set<int> st1,st2;
        for(int i=1;i<=n;i++){
            st1.insert(dsa.find(i));
            st2.insert(dsb.find(i));
        }
        if(st1.size()==1 and st2.size()==1){
            if(dsa.sizer[*(st1.begin())]==n && dsb.sizer[*(st2.begin())]==n){ //chking the size of the component
                return cnt;
            }
        }
        return -1;
    }
};
