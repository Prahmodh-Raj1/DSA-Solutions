//Problem link: https://codeforces.com/contest/1701/problem/C
//TC:O(NLOGM) SC:O(1)

void solve(){
    ll n,m; cin>>n>>m;
    vector<ll> v(n+1);
    ll x;
    for(int i=0;i<m;i++){
        cin>>x;
        x--;
        v[x]++;  //counting the no. of jobs that the person has to perform
    }
    ll l=0,r=m;  //worst case is that each work takes 2 hours
    while(l<r){
        ll mid=(l+r)/2;  
        ll time=0,work=0;
        for(int i=0;i<n;i++){  //chking if in the mid time, if we can complete all the tasks
            if(v[i]<=mid){   //if the perosn can do all the tasks by himself
                time+=(mid-v[i])/2;  //calculating the free time of the people in time variable
                //dividing by two, coz the other tasks are not his speciality, so it would take him 2 hours to complete
            }else{  //if he cant do all the tasks by himself
                work+=v[i]-mid;  //work contains the tasks that others need to do, except the current person
            }
        }
        if(time>=work) r=mid;  //if free time is larger than the work to be done, then we need to choose a shorter time to search for
        else l=mid+1;   //search for a bigger time
         
    }
    
    cout<<l<<"\n";
    
}
