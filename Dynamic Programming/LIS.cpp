//Problem link: https://leetcode.com/problems/longest-increasing-subsequence/
//TC: O(N^2) SC: O(N)

class Solution {
public:
    int dp[2505];
    int rec(int level,int n,vector<int>& nums){
        if(level<0) return 0;
        if(dp[level]!=-1) return dp[level];
        int ans=1;
        for(int i=0;i<level;i++){
            if(nums[level]>nums[i]){
                ans=max(ans,1+rec(i,n,nums));
            }
        }
        dp[level]=ans;
        return dp[level];
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int lis=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            lis=max(lis,rec(i,n,nums));
        }
        return lis;
    }
};

//TC :O(NLOGN) SC:O(N) and priniting the LIS
void LisNlogN(int n,vector<int>& arr){
	
	for(int i=0;i<n;i++) cin>>arr[i];
	vector<int> lis;
	int insertat[n]; 
	for(int i=0;i<n;i++){//O(NLOGN)
		if(lis.empty() || lis.back()<arr[i]){ 
			lis.push_back(arr[i]);
			insertat[i]=lis.size()-1;
		}else{ //LogN
			auto it=lower_bound(lis.begin(), lis.end(),arr[i]); 
			*it=arr[i]; //replace the elet;
			insertat[i]=it-lis.begin()+1;
		}

	}
	cout<<lis.size()<<"\n";
	for(int i=0;i<n;i++){
		cout<<insertat[i]<<" ";
	}
  cout<<"\n";
	vector<int> finals;
	int curlen=lis.size(); 
	for(int i=n-1;i>=0;i--){
		if(insertat[i]==curlen){ 
			finals.push_back(arr[i]);
			curlen--; 
		}
	}
	reverse(finals.begin(),finals.end());
	for(auto it:finals) cout<<it<<" ";
}
