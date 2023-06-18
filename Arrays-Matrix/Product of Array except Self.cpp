//Problem link: https://leetcode.com/problems/product-of-array-except-self/description/
//TC: O(N) SC: O(N)
//Explanation: https://leetcode.com/problems/product-of-array-except-self/solutions/1342916/3-minute-read-mimicking-an-interview/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        int pref[n],suf[n];
        pref[0]=1;
        suf[n-1]=1;
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]*nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            suf[i]=suf[i+1]*nums[i+1];
        }
        for(int i=0;i<n;i++){
            ans[i]=pref[i]*suf[i];
            
        }
        return ans;
    }
};

//TC: O(N) SC:O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,1);
        int cur=1;
        
        for(int i=0;i<n;i++){
            ans[i]*=cur;
            cur*=nums[i];
        }
        cur=1;
        for(int i=n-1;i>=0;i--){
            ans[i]*=cur;
            cur*=nums[i];
        }
        return ans;
    }
};
