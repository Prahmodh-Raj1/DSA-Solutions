//Problem link: https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/
class Solution {
private:
    int helper(vector<int>& nums,int ind,int n){
        if(ind==n-2){

            return 0;
            //can't make decisions from here
        }
        if(nums[ind]==0){
            //make the swap
            nums[ind]^=1;
            nums[ind+1]^=1;
            nums[ind+2]^=1;
            return 1 + helper(nums,ind+1,n);
        }else{
            //don't swap
            return helper(nums,ind+1,n);
        }
    }
public:
    int minOperations(vector<int>& nums) {
        //an element gets flipped if it's chosen for flipping for an odd number of times
        //the first element can be changed by only flipping one range

        //so if the first element is 0, we've to take that range and flip it, we've no other choice
        //we do the flipping, then  we apply a recursive function 
        //In the recursive function, don't flip it if it's not a 1
        int n = nums.size();
        int cnt = helper(nums,0,n);
        for(auto it:nums){
            if(it!=1) return -1;
        }
        return cnt;
    }
};

//Another solution

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), i = 0, j = 2, ans = 0;
        while(j < n){
            if(nums[i] == 0){
                ans++;
                for(int k = i; k < i + 3; k++){
                    nums[k] = nums[k] == 0 ? 1 : 0;
                }
            }
            i++, j++;
        }
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) return -1;
        }
        return ans;
    }
};
