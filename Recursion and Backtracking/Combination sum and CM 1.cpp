Comb Sum1: An element can be used as many times as possible
//Problem link:  https://leetcode.com/problems/combination-sum/
//TC: O(2^N) 
class Solution {
private:
    void helper(vector<vector<int>>& ans,vector<int>& cur,vector<int>& candidates,int target,int n,int ind,int sum){
        if(sum>target) return;
        if(sum==target){
            ans.push_back(cur);
            return;
        }
        for(int i=ind;i<n;i++){
            cur.push_back(candidates[i]);
            sum+=candidates[i];
            helper(ans,cur,candidates,target,n,i,sum);
            sum-=candidates[i];
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        vector<int> cur;
        helper(ans,cur,candidates,target,n,0,0);
        return ans;

    }
};

Comb sum-2: using each element only once
//Problem link: https://leetcode.com/problems/combination-sum-ii/
//TC: O(2^N)
class Solution {
    private:
    void helper(vector<vector<int>>& ans,vector<int>& cur,vector<int>& candidates,int target,int n,int ind,int sum){
        if(sum>target) return;
        if(sum==target){
            ans.push_back(cur);
            return;
        }
        for(int i=ind;i<n;i++){
            if(i==ind or candidates[i]!=candidates[i-1]){  //checking for non-duplicate consecutive entries only
                cur.push_back(candidates[i]);
                sum+=candidates[i];
                helper(ans,cur,candidates,target,n,i+1,sum);
                sum-=candidates[i];
                cur.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        vector<int> cur;
        helper(ans,cur,candidates,target,n,0,0);
        return ans;
    }
};
