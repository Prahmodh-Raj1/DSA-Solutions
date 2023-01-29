Problem Statement

Let there be N workers and N jobs. Any worker can be assigned to perform any job, incurring some cost that may vary depending on the work-job assignment. It is required to perform all jobs by assigning exactly one worker to each job and exactly one job to each agent in such a way that the total cost of the assignment is minimized.

Input Format
Number of workers and job: N
Cost matrix C with dimension N*N where C(i,j) is the cost incurred on assigning ith Person to jth Job.

Sample Input
4

[
9 2 7 8
6 4 3 7
5 8 1 8
7 6 9 4
]

Sample Output
13

Constraints
N <= 20




int func(int i,int bitmask,int& n,vector<vector<int>>& cost,vector<vector<int>>& dp){
    if(i==n) return 0;
    if(dp[i][bitmask]!=-1) return dp[i][bitmask];
    int mini=1e9;
    for(int j=0;j<n;j++){
        if(bitmask & (1<<j)){ //j'th person is available
            int ans=cost[j][i] + func(i+1,(bitmask ^ (1<<(j))),n,cost,dp);
            mini=min(ans,mini);
        }
    }
    return dp[i][bitmask]=mini;
}
int solve(){
    //we have two states for the dp here : i,bitmask
    //the bitmask will store the remaining ppl who can be assigned the jobs, leaving alone the 
    //the ones who have already been assigned a job, which are marked  0 in the mask
    //there are N people, starting from 1,....N needed to do N jobs, so we need to return the minimum of all the 
    //possible job assignments
    //dp(i,mask): what is the minimum cost required to assign ppl from job no. i to n and the ppl available are 
    //represented by the mask available
    //initially, the function call would look like func(1,(1<<n)-1), 1<<n is 2^n, initially all the ppl are
    //available to perform the jobs
    //Recurrence:
    //dp(i,mask) = Cji + dp(i+1,mask| turn off the j'th bit), try this for all valid j, then minimum of them all will be the dp(i,mask)
    //a person is considered valid, if that particular bit is 1
    //TC:O(N^2 * 2^N)   SC:O(N*2^N) , the bitmask can produce 2^N possible combinations
    //Cji: assigning the j'th person to the i'th job
    
    //int cost[21][21];
    int n;
    
    cin>>n;
    vector<vector<int>> cost(n,vector<int>(n,0));
    int x;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>x;
            cost[i][j]=x;
            //cin>>cost[i][j]; //the cost of assigning the i'th person to the j'th job
        }
    }
    int temp=(1<<n);
    vector<vector<int>> dp(n+1,vector<int>(temp+1,-1));
    return func(0,temp-1,n,cost,dp);
}
