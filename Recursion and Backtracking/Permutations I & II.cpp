Permutations: 1
//Problem link:  https://leetcode.com/problems/permutations/
//TC: O(2^N) 
class Solution {
private:
    void helper(vector<vector<int>>& ans,vector<int>& cur,vector<int>& nums,int n){
        if(cur.size()==n){
            ans.push_back(cur);
            return;
        }
        for(int i=0;i<n;i++){
            if(find(cur.begin(), cur.end(), nums[i]) != cur.end()) continue;
            cur.push_back(nums[i]);
            helper(ans,cur,nums,n);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        int n=nums.size();
        helper(ans,cur,nums,n);
        return ans;
    }
};

Permutations- 2
//Problem link: https://leetcode.com/problems/permutations-ii
//TC- same as above
public class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if(nums==null || nums.length==0) return res;
        boolean[] used = new boolean[nums.length];
        List<Integer> list = new ArrayList<Integer>();
        Arrays.sort(nums);
        dfs(nums, used, list, res);
        return res;
    }

    public void dfs(int[] nums, boolean[] used, List<Integer> list, List<List<Integer>> res){
        if(list.size()==nums.length){
            res.add(new ArrayList<Integer>(list));
            return;
        }
        for(int i=0;i<nums.length;i++){
            if(used[i]) continue;
            if(i>0 &&nums[i-1]==nums[i] && !used[i-1]) continue;
            used[i]=true;
            list.add(nums[i]);
            dfs(nums,used,list,res);
            used[i]=false;
            list.remove(list.size()-1);
        }
    }
}
