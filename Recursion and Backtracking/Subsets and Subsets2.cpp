//SUBSETS:
//Problem link: https://leetcode.com/problems/subsets/description/
//TC: O(2^N) SC:O(1) - Auxillary stack space
class Solution {
private:
    void helper(vector<vector<int>>& ans,vector<int>& cur,vector<int>& nums,int ind,int n){
        
        ans.push_back(cur);
        for(int i=ind;i<n;i++){
            cur.push_back(nums[i]);
            helper(ans,cur,nums,i+1,n);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        vector<int> cur;
        helper(ans,cur,nums,0,n);
        return ans;
    }
};

//SUBSETS 2:
//Problem link: https://leetcode.com/problems/subsets-ii/description/
//TC and SC same as the previous one
class Solution {
public:
    std::vector<std::vector<int> > subsetsWithDup(std::vector<int> &nums) {
		std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int> > res;
		std::vector<int> vec;
		subsets(res, nums, vec, 0);
		return res;
    }
private:
	void subsets(std::vector<std::vector<int> > &res, std::vector<int> &nums, std::vector<int> &vec, int begin) {
		res.push_back(vec);
		for (int i = begin; i != nums.size(); ++i) {
            if(i==begin or nums[i]!=nums[i-1]){
			    vec.push_back(nums[i]);
			    subsets(res, nums, vec, i + 1);
			    vec.pop_back();
            }
		}
	}
};
