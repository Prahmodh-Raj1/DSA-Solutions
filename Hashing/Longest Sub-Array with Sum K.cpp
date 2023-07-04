//Problem link: https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//Hashing approach: 
int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
        unordered_map<int,int> mp;
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==k){
                ans=i+1;
            }
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }
            if(mp.find(sum-k)!=mp.end()){
                ans=max(ans,i-mp[sum-k]);
            }
        }
        return ans;
    }

//Two pointers approach: only for positive numbers:
int lensubarray(int arr[],int n,int k){
        int i=0,j=0,sum=0;
        int ans=0;
        while(j<n){
            sum+=arr[j];
            if(sum==k){
                ans=max(ans,j-i+1);
                j++;
            }
            else if(sum<k){
                j++;
            }else{
                while(sum>k){
                    sum-=arr[i];
                    i++;
                }
                if(sum==k){
                    ans=max(ans,j-i+1);
                }
                j++;  //moving the j pointer since in this current window, we know the sum is less than k
            }
        }
        return ans;
    }


