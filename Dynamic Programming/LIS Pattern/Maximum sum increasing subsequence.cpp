//prob link: https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
//TC: O(N^2) SC: O(N)
int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int> ans(n);
	    for(int i=0;i<n;i++) ans[i] = arr[i];
	    
	    int maxi=ans[0];
	    for(int i=0;i<n;i++){
	        int curmax = ans[i];
	        for(int prev=0;prev<i;prev++){
	            
	            if(arr[prev]<arr[i] && (ans[prev] + ans[i]) > ans[i]){
	               
	                curmax = max(curmax,ans[prev]+ans[i]);
	                
	            }
	            
	        }
	        ans[i] =curmax;
	        maxi = max(maxi,ans[i]);
	    }
	    
	    return maxi;
	}  
