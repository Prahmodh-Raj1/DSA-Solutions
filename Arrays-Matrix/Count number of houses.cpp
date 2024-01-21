//Problem link: https://leetcode.com/problems/count-the-number-of-houses-at-a-certain-distance-i/
//TC: O(N^2) SC: O(N)
class Solution {

public:
    vector<int> countOfPairs(int n, int x, int y) {
        if(x>y) return countOfPairs(n,y,x);
        //we keep x<=y
        vector<int> ans(n,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                int index = i-j;
                index = min(index,abs(j-x)+1+abs(i-y));
                if(index>=1){
                    ans[index-1]+=2;
                }
            }
        }
        return ans;
        
  }
};
//Explanation:https://leetcode.com/problems/count-the-number-of-houses-at-a-certain-distance-i/solutions/4600589/simple-logic-explained-easy-to-understand-c-o-n-2/
