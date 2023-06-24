//Problem link: https://leetcode.com/problems/wiggle-subsequence/
//TC:O(N) SC:O(N)
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<int> dpup(n,0),dpdown(n,0);
        dpup[0]=1;
        dpdown[0]=1;
        
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                dpup[i]=dpdown[i-1]+1; //the previous should have been a down
                dpdown[i]=dpdown[i-1];
            }
            else if(nums[i]<nums[i-1]){  //the previous should have been an up
                dpdown[i]=dpup[i-1]+1;
                dpup[i]=dpup[i-1];
                
            }else{  //equal elements, so it's no change
                dpup[i]=dpup[i-1];
                dpdown[i]=dpdown[i-1];
            }
        }
        return max(dpup[n-1],dpdown[n-1]);
    }
};

//TC: O(N) SC:O(1)
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        
        int upp=1,downn=1;
        int curup=upp,curdown=downn;
    
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                curup=downn+1;
                curdown=downn;
                upp=curup;
                downn=curdown;
            }
            else if(nums[i]<nums[i-1]){
                curdown=upp+1;
                curup=upp;
                upp=curup;
                downn=curdown;
               
                
            }else{
                curup=upp;
                curdown=downn;
                upp=curup;
                curdown=downn;
               
            }
        }
        return max(curup,curdown);
    }
};
