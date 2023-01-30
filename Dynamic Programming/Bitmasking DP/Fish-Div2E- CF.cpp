//Problem link: https://codeforces.com/contest/16/problem/E
double pmove(int prevday_mask,int j,int& n,vector<vector<double>>& prob){ //the j'th fish needs to die
    int k= __builtin_popcount(prevday_mask);
    ll den = (k*(k-1))/2;
    double  moveprob =0;
    for(int fish=0;fish<n;fish++){
        if(prevday_mask & (1<<fish)){
            moveprob+=prob[fish][j];
        }
    }
    return moveprob/den;
}

double func(int mask,int& n,vector<vector<double>>& prob,vector<double>& dp){
    int alive=__builtin_popcount(mask); //will give the no. of bits that are set on
    if(alive==n) return 1;
    if(dp[mask]> -0.9){// to avoid directly comparing double
        return dp[mask];
    }
    double answer=0;
    for(int fish=0;fish<n;fish++){
        if(!(mask & (1<<fish))){ //if this particular fish is dead, then one day ago, it could have been alive,
        //so find the prob of the previous state happening and from that we derive the probability of this state ever happening
        
        //find the prob of moving from the previous day to the current day ,then we multiply these two together and add it to the answwer
        int prevday_mask= mask ^ (1<<fish);
        double prevday= func(prevday_mask,n,prob,dp); //calling with that particular bit on
        answer+=prevday_bitmask*prob_prevday_to_cur_day(prevday_mask,fish,n,prob);
        
            
        }
    }
    return dp[mask]=answer;
}
void solve(){
    //let the fishes be represented in a bitmask as S={1,2,3,....N}
    //then after each day, one pair of fish will fight,
    // and the remaining fish might be {2,3,..N}, {1,3...N}...{1,2,....N-1}
    //Total no. of pairs of fish that can be selected: N*(N-1)/2 = k(say)
    //Suppose we wanna choose the pair (1,2), then the probability of choosing that pair is
    //1/k. And the probability of 1 losing is (1/k)*P[2][1], and similarly for all the pairs containing 1
    //So the total prob that 1 loses is (1/k)* (P21 + P31+....Pn1);
    //This is for the set transition from {1,2,...N} to {2,3,....N}
    //dp(S) represents prob of having the fishes in the set S in the pond, i.e all the fishes are dead except for the fishes
    //present in the set S
    //initially dp({1,2,3...S}) is 1
    //SO the final soln would be dp({1}), dp({2}),....dp({n})
    
    //Say that 1 is winner, so the possible previous states are {1,2}, {1,3},...{1,n}
    //So the probability of reaching the previous states is P1i * dp({1,i})
    //The recurrence is given by
    //If there are k fishes alive in the previous state, then we will have kC2 possible ways to choose a pair of fish
    //Probability is (1/kC2) [P1j + P2j +....]
    
    int n; cin>>n;
    vector<vector<double>> prob(n,vector<double>(n,0));
    double x;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>x;
            prob[i][j]=x;
        }
    }
    vector<double> dp((1<<n));
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cout<<func((1<<n),n,prob,dp)<<" ";
    }
}
int main() {
	
	nfs;
	#ifndef ONLINE_JUDGE
    	freopen("input.txt","r",stdin);
    	freopen("output.txt","w",stdout);
    	#endif
	solve();


	
    
	return 0;
}
