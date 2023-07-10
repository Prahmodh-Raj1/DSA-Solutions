//problem link: https://leetcode.com/problems/4sum
//TC: O(N^2) SC: O(N)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int  j=i+1;j<n;j++){
//FIX TWO numbers and look out for the rest of the sum
                int left2 = target - nums[i]-nums[j];
                int l=j+1;
                int r= n-1;
                while(l<r){
                    int lrsum = nums[l]+nums[r];
                    if(lrsum>left2) r--;
                    else if(lrsum<left2) l++;
                    else{
                        vector<int> curans(4);
                        curans[0]=nums[i];
                        curans[1]=nums[j];
                        curans[2]=nums[l];
                        curans[3]=nums[r];
                        ans.push_back(curans);
                        //dealing(skipping) with the duplicates
                        while(l<r and nums[l]==curans[2]) l++;
                        while(l<r and nums[r]==curans[3]) r--;
                    }
                }
                
                while(j+1<n and nums[j]==nums[j+1]) j++;  //skipping the duplicates

            }
            while(i+1<n and nums[i]==nums[i+1]) i++;
        }
        return ans;
        
    }
};
