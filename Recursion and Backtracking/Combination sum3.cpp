//prob link: https://leetcode.com/problems/combination-sum-iii
class Solution {
public:
    vector<vector<int>> ans; 
    void helper(vector<int>& cur,int k,int sum,int start,int n){
        if(sum<0 or cur.size()>k) return;
        if(sum==n){
            if(cur.size()==k){
                ans.push_back(cur);
            }
            return;
        }
        for(int i=start;i<=9;i++){
            cur.push_back(i);
            sum+=i;
            helper(cur,k,sum,i+1,n);
            sum-=i;
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> cur;
        
        helper(cur,k,0,1,n);
        return ans;
    }
};
