//TC:O(N*Weight) SC:O(2*Weight)
class Solution{
public:
    int knapSack(int n, int W, int val[], int wt[])
    {
        // code here
        vector<int> prev(W+1,0),cur(W+1,0);
        for(int t=0;t<=W;t++){
            prev[t]=(t/wt[0])*val[0];
        }
        for(int i=1;i<n;i++){
            for(int w=0;w<=W;w++){
                int nottake=prev[w];
                int take=INT_MIN;
                if(w>=wt[i]) take=val[i]+cur[w-wt[i]];
                cur[w]=max(take,nottake);
            }
            prev=cur;
        }
        return prev[W];
    }
};

//Single array optimization
int knapSack(int n, int W, int val[], int wt[])
    {
        // code here
        vector<int> prev(W+1,0);
        for(int t=0;t<=W;t++){
            prev[t]=(t/wt[0])*val[0];
        }
        for(int i=1;i<n;i++){
            for(int w=0;w<=W;w++){
                int nottake=prev[w];
                int take=INT_MIN;
                if(w>=wt[i]) take=val[i]+prev[w-wt[i]];
                prev[w]=max(take,nottake);
            }
            
        }
        return prev[W];
    }
