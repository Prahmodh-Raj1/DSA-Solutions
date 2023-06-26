//Problem link: https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/
//TC:O(Nlog(maxi) SC:O(1)
class Solution {
public:
    
    bool check(vector<int>& nums,int mid,int oper){
        int cnt=0;
        for(auto it:nums){
            if(it<=mid){
                continue;
            }else{
                cnt+=((it-1)/mid);  //finding the number of moves required to get the element within the mid element
            }

        }
        return cnt<=oper;  //checking if the number of operations taken is lesser than the the total operations count 
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        
        int low = 1,high=*max_element(nums.begin(),nums.end());  //possible answers
        while(low<high){
            int mid = (low+high)/2;
            if(check(nums,mid,maxOperations)){
                high=mid;
            }else low= mid+1;
        }
        return low;
    }
};
