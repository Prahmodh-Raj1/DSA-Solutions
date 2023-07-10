//Problem link: https://leetcode.com/problems/graph-connectivity-with-threshold/
//TC: O(Nroot(N)) SC: O(N)
//The maximum number of prime factors a number can have is LogN - base 2
//For explanation of the approach, refer the solution to the problem : Greatest Common divisor traversal
class DSU{
private:
    vector<int> parent,ranks;
public:
    DSU(int n){
        parent.resize(n);
        ranks.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            ranks[i]=1;
        }
    }
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }
    void unite(int x,int y){
        x=find(x);
        y=find(y);
        if(ranks[x]>ranks[y]){
            parent[y]=x;
        }else if(ranks[y]>ranks[x]){
            parent[x]=y;
        }else{
            parent[y]=x;
            ranks[x]++;
        }
    }
};

class Solution {
private:
unordered_set<int> factors(int n)
{
    unordered_set<int> st;
    // Note that this loop runs till square root
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, print only one
            if (n/i == i)
                st.insert(i);
  
            else // Otherwise print both
                st.insert(i);
                st.insert(n/i);
        }
    }
    
    return st;
}
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        DSU ds(n+1);
        unordered_map<int,int> index;
        for(int i=1;i<=n;i++){
            unordered_set<int> factor = factors(i);
            for(auto it:factor){
                if(it>threshold and index.find(it)!=index.end()){
                    ds.unite(index[it],i);
                }
                if(it>threshold) index[it]=i;
            }
        }
        vector<bool> ans;
        for(auto it:queries){
            int parent1 = ds.find(it[0]);
            int parent2=ds.find(it[1]);
            if(parent1==parent2){
                ans.push_back(true);
            }else ans.push_back(false);
        }
        return ans;
    }
};
