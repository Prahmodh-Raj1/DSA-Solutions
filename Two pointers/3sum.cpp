//Problem link: https://leetcode.com/problems/3sum/
//TC: O(N^2) SC: O(1)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> res;
        //fixing one number and finding the other two
        for(int i=0;i<n;i++){
            int required = -nums[i];
            int j=i+1;
            int k=n-1;
            while(j<k){
                int twosum = nums[k] + nums[j];
                if(twosum>required){
                    k--;
                }
                else if(twosum<required){
                    j++;
                }
                else{
                    vector<int> triplet ={nums[i],nums[j],nums[k]};
                    res.push_back(triplet);
                    //skipping the duplicates
                    while(j<k && nums[j]==triplet[1]) j++;
                    while(j<k && nums[k]==triplet[2]) k--;
                }
            }
            //skipping the duplicates
            while(i+1<n and nums[i]==nums[i+1]) i++;
        }
        return res;
    }
};
