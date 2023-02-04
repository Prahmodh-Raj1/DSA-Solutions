//Problem link: https://leetcode.com/problems/2-keys-keyboard/
//TC:O(N*LOG(N) base i) SC;O(1)
class Solution {
public:
 
    int minSteps(int n) {
      
        int ans=0;
        for(int i=2;i<=n;i++){
            while(n%i==0){
                ans+=i;
                n/=i;
            }
        }
        return ans;
      
    }
};
