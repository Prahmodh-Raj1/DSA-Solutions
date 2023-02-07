//Problem link: https://leetcode.com/problems/best-team-with-no-conflicts/
//TC:O(N^2) SC:O(N)
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> v;
        int n=scores.size();
        for(int i=0;i<n;i++){
            v.push_back({ages[i],scores[i]});
        }
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        vector<int> dp(n+1,-1);
        int ans=-1;
        for(int i=0;i<n;i++){
            dp[i]=v[i].second;
            for(int j=0;j<i;j++){
                if(v[i].second<=v[j].second){
                    dp[i]=max(dp[i],v[i].second+dp[j]);
                }
            }
            ans=max(ans,dp[i]);
        }

        return ans;
    }
