//Space optimised solution
//TC:O(N^2) SC:O(N)
int knapsack(vector<int> wt, vector<int> val, int n, int maxWeight) 
{
	vector<int> prev(maxWeight+1,0);
    for(int i=wt[0];i<=maxWeight;i++) prev[i]=val[0]; //base case
    for(int i=1;i<n;i++){
        for(int w=maxWeight;w>=0;w--){
            int nottake=prev[w];
            int take=INT_MIN;
            if(wt[i]<=w){
                take=val[i]+prev[w-wt[i]];
            }
            prev[w]=max(take,nottake);
        }
    }
    return prev[maxWeight];
    
}
