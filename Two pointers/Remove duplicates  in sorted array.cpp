//Problem link: https://leetcode.com/problems/remove-duplicates-from-sorted-array
//TC: O(N) SC: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int cnt=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]) cnt++;
            else nums[i-cnt]=nums[i];
        }
        return nums.size()-cnt;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int ind=0;
        int i=0;
        while(i<n){
            if(i+1<n){
                int j=i+1;
                
                while(j<n and nums[j]==nums[i]) j++;
                if(j==i+1){
                    //no duplicates
                    nums[++ind]=nums[j];
                    i=j;
                    continue;
                }else if(j==n){
                    break;
                }
                else{
                    nums[++ind]=nums[j];
                    i=j;
                    continue;
                }
                
            }else break;
        }
        int k=++ind;
        for(int i=++ind;i<n;i++){
            nums[i]=1e9;
        }
        return k;
    }
};
