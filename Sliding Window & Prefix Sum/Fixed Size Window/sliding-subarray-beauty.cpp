//Problem link: https://leetcode.com/problems/sliding-subarray-beauty
//TC: O(n) SC: O(N)
class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n= nums.size();
        vector<int> ans;
        map<int,int> mp;
        /*Using map we will keep storing the count of -50 to 50 in each window of size k.
Then with each window need to search the xth smallest element by counting the number of occurance of each element, in the map*/
        for(int i=0;i<n;i++){
            mp[nums[i]]++;  //storing the frequency of the elemnts
            if(i>=k-1){
                //we've reached the current window limit and going beyond it for the next windows
                if(i>=k) mp[nums[i-k]]--; //reducing window size
                int sum=0,xneg=0;
                for(auto it:mp){
                    sum+=it.second;
                    if(sum>=x){  //finding the x'th smallest -ve element in the window
                      
                        if(it.first>0){
                            xneg=0;
                        }else xneg = it.first;
                        break;
                    }
                }
                ans.push_back(xneg);
            }
        }
        return ans;
    }
};
