//Problem link: 
//TC: O(N) SC: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int i=0,j=0;
        int sum=0;
        int maxi=INT_MIN;
        while(j<n){
            sum+=nums[j];
            maxi = max(maxi,sum);
            while(sum<0){
                sum-=nums[i++];
            }
           
            j++;
        }
       
        return maxi;
    }
};

//TC: O(N) SC: O(1)  DP approach
int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int maxi=nums[0];
        int prev=nums[0],cur=0;
        for(int k=1;k<n;k++){
            cur = max(prev+nums[k],nums[k]);
            maxi = max(cur,maxi);
            prev=cur;
        }
       
        return maxi;
    }
