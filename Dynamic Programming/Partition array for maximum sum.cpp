//Problem link: https://leetcode.com/problems/partition-array-for-maximum-sum/
class Solution {
public:

    //TC:O(N*K) SC:O(N)
    int func(int i,vector<int>& arr,int k,vector<int>& dp){
        int n=arr.size();
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int len=0;
        int maxsum=INT_MIN;
        int maxi=INT_MIN;
        
        for(int j=i;j< min(j+k,n);j++){
            len++;
            maxi=max(arr[j],maxi);
            int sum=maxi*len + func(j+1,arr,k,dp);
            maxsum= max(maxsum,sum);
        }
        return dp[i]=maxsum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        //try out all possible partitions from that index, we stop after we cross subarray of length k
        //the possible partitions go from j=ind; j<min(n,ind+k);j++
        //once we cause a partition, the sum of the subarray is the no.of elments in the subarray*max_ele in the subarray
        int n=arr.size();
        vector<int> dp(n+1,0);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            int len=0;
            int maxi=-1;
            int maxsum=-1;
            for(int j=i;j<min(i+k,n);j++){
                len++;
                maxi=max(maxi,arr[j]);
                int sum=maxi*len +  dp[j+1];
                maxsum=max(sum,maxsum);
            }
            dp[i]=maxsum;
        }
        return dp[0];
        //return func(0,arr,k,dp);
    }
};
