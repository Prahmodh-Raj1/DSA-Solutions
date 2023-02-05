//Problem link: https://leetcode.com/problems/house-robber-iv/description/
//TC:O(NlogN) SC:O(1)
class Solution {
public:
    bool isPossible(int x,vector<int>& nums,int k){
        //this function chks the following
        //Shld rob atleast k houses
        //Can't rob adjacent houses
        //Can rob only the houses that have money<=x
        int lastindex=-10;
        int countstolen=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>x) continue;
            if(lastindex==i-1) continue;
            countstolen++;
            lastindex=i;
        }
        return countstolen>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        int l=1;
        int r=1e9;
        while(l<r){
            int mid= l+ (r-l)/2;
            if(isPossible(mid,nums,k)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};
