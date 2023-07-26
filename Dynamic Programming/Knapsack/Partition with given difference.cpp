//Problem link: https://www.codingninjas.com/studio/problems/count-subsets-with-sum-k_3952532
//TC :O(N*target) SC:O(N)
//S1 + S2 = Total
//S1> = S2
//S1 - S2 = D
//Solving the two equations, we get the expression for S2, that's our target sum
int findWays(vector<int> &num, int k){
    int n = num.size();

    vector<int> prev(k+1,0);
    
    prev[0] =1;
    
    if(num[0]<=k)
        prev[num[0]] = 1;
    
    for(int ind = 1; ind<n; ind++){
        vector<int> cur(k+1,0);
        cur[0]=1;
        for(int target= 1; target<=k; target++){
            
            int notTaken = prev[target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = prev[target-num[ind]];
        
            cur[target]= notTaken + taken;
        }
        
        prev = cur;
    }
    
    return prev[k];

    
}
