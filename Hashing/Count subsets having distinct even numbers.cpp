//Problem link: https://practice.geeksforgeeks.org/problems/count-subsets-having-distinct-even-numbers5726/1
//TC: O(N+N) SC: O(N)
//Answer is 2^(no. of distinct even numbers) - 1
long long power(long long int x,long long int y){
    long long int ans=1;
    for(long long int i=1;i<=y;i++){
        ans=ans*x;
    }
    return ans;
}
long long countSubsets(int a[], int n) {
    set<long long int>s;
    for(long long int i=0;i<n;i++){
        if(a[i]%2==0){
                s.insert(a[i]);
            }
        }
    long long int k=s.size();
    long long int ans=(power(2,k)-1);
    return ans;
}
