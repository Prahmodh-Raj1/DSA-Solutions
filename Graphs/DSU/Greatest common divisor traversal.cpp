//problem link: https://leetcode.com/problems/greatest-common-divisor-traversal
//Approach 1:
Storing unique factors and applying DFS to check number of components. if there is only one component that means all numbers are connected with each other either directly or indirectly, so return true else return false..

Approach
Calculate unique factors of each number and if that factor occurs for another number also so these two numbers have gcd>1. So, we can have an undirected edge b/w these two numbers. After that just simple DFS traversal to count components.

How to check common factors between two numbers -> we will simple store every factor with index of last number(say in a map) in which it occured and if this factor occured again then we will create and edge from current number's index to index of that number wwhose index is stored with this number in map

  class Solution {
public:

    unordered_set<int> UniquePrimeFactors(int n){
        unordered_set<int> factors;
        for(int i=2; i<= sqrt(n); i++){
            while(n%i == 0){
                factors.insert(i);
                n /= i;
            }
        }

        if(n > 1) factors.insert(n);

        return factors;
    }

    void dfs(int i, set<int>& vis, vector<vector<int>>& adj){
        vis.insert(i);

        for(int node: adj[i]){
            if(vis.find(node) == vis.end()) dfs(node, vis, adj);
        }
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> adj(n);

        unordered_map<int, int> lastIndex;

        for(int i=0; i<nums.size(); i++){
            unordered_set<int> primeFactors = UniquePrimeFactors(nums[i]);

            for(int factor: primeFactors){
                if(lastIndex.find(factor) != lastIndex.end()){
                    int prevIndex = lastIndex[factor];
                    adj[prevIndex].push_back(i);
                    adj[i].push_back(prevIndex);
                }

                lastIndex[factor] = i;
            }
        }

        set<int> vis;
        dfs(0, vis, adj);

        return vis.size() == n;
    }
};

//Approach 2: Using DSU
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
class Solution{
private:
    unordered_set<int> UniquePrimeFactors(int n){
        unordered_set<int> factors;
        for(int i=2; i<= sqrt(n); i++){
            while(n%i == 0){
                factors.insert(i);
                n /= i;
            }
        }

        if(n > 1) factors.insert(n);

        return factors;
    }
public:
    bool canTraverseAllPairs(vector<int>& nums){
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int> representative(maxi+1,-1); //we'll choose the first element as the representative fro the prime factor, stores the index
        unordered_map<int,int> index;
        DSU ds(n);
        for(int i=0;i<n;i++){
            unordered_set<int> primefactors = UniquePrimeFactors(nums[i]);
            for(auto it:primefactors){
                if(it>1 and index.find(it)!=index.end()){
                    ds.unite(index[it],i);
                }
                if(it>1) index[it]=i;
            }
        }
        
        set<int> stparents;
        for(int i=0;i<n;i++){
            stparents.insert(ds.find(i));
        }
        return stparents.size()==1;
    }
};
