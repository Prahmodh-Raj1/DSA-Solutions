//Prob link: https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
//TC: O(NlogN) SC: O(1)
class Solution {
private:
long long int mod =1e9 + 7;
int power(int a,int b){
  if(b==0)  return 1;
  int x = (power(a,b/2))%mod;
  if(b%2==0)  return ((x%mod)*(x%mod))%mod;
  else   return (a*(((x%mod)*(x%mod))%mod)%mod);
}
public:
    int numSubseq(vector<int>& nums, int target) {
        long long int cnt=0;
        
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1;
        while(l<=r){
            int sum = nums[l]+nums[r];
            if(sum<=target){
                
                cnt=(cnt+(long long int)power(2,r-l))%mod;
                l++;
            }else{
                r--;
            }
        }
        return (int)cnt;
    }
};
