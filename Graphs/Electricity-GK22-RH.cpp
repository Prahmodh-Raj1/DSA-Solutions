//Problem link: https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb1b6/0000000000c47c8e
//TC : O(N) SC:O(N*E)+O(N)
#include<bits/stdc++.h>
using namespace std;
int dfs(int i,int p,vector<vector<int>>&adj,vector<int>&power,vector<int>& dp){
    if(power[i]>=p) return 0;
    if(dp[i]!=-1) return dp[i];
    
    int ans=0;
    for(auto j:adj[i]){
        if(power[j]<p)
            ans+=dfs(j,power[i],adj,power,dp);
    }
    dp[i]=ans+1;
    return dp[i];
    
}

int main(){
    int t;
    cin>>t;
    for(int T=1;T<=t;T++){
        cout<<"Case #"<<T<<": ";
        int n;
        cin>>n;
        vector<int> dp(n,-1);
        vector<int>power(n);
        for(int i=0;i<n;i++)
            cin>>power[i];
        vector<vector<int>>adj(n+1);
        for(int i=0;i<n-1;i++){
            int x,y;
            cin>>x>>y;
            adj[x-1].push_back(y-1);
            adj[y-1].push_back(x-1);
        }
        
        for(int i=0;i<n;i++){
            dfs(i,INT_MAX,adj,power,dp);
            
        }
        int res=*max_element(dp.begin(),dp.end());
        cout<<res<<endl;
    }
    return 0;
}
