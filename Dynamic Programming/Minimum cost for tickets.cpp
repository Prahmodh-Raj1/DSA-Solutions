//Problem link: https://leetcode.com/problems/minimum-cost-for-tickets/
//Memoization
    int func(int i,vector<int>& days,vector<int>& costs,vector<int>& dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int oneday = costs[0] + func(i+1,days,costs,dp);
        int j;
        for(j=i;j<n and days[j]<days[i]+7;j++);
        int sevenday = costs[1]+ func(j,days,costs,dp);
        for(j=i;j<n and days[j]<days[i]+30;j++);
        int thirtyday = costs[2] + func(j,days,costs,dp);
       
        
        
        
        return dp[i]=min(oneday,min(sevenday,thirtyday));
        }

       
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n=days.size();
        
        vector<int> dp(366,-1);
        return func(0,days,costs,dp);
    }
//Tabulation
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_map<int,int> tickets;
        tickets[1] = costs[0];
        tickets[7] = costs[1];
        tickets[30] = costs[2];
        
        vector<int> dp(366, INT_MAX);
        dp[0] = 0;
        for(int i=1; i<366; ++i){
            if(find(days.begin(), days.end(), i) == days.end()){
                dp[i] = dp[i-1];
                continue;
            }
            for(auto ticket : tickets){
                dp[i] = min(dp[i], dp[max(0, i-ticket.first)] + ticket.second);
            }
        }
        
        return dp[365];
    }
