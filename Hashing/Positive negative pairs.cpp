//Problem link: https://practice.geeksforgeeks.org/problems/positive-negative-pair5209/1
//TC: O(N) SC: O(N)
vector <int> findPairs(int arr[], int n) 
    { 
    	vector<int> result; 
    	map<int, int> ump; 
    
    	for (int i = 0; i < n; i++) { 
    	    
    	 
    	    ump[abs(arr[i])]++;
    	    if(ump[abs(arr[i])]==2){
            	result.push_back((-1)*abs(arr[i])); 
    			result.push_back(abs(arr[i])); 
   
    		} 
    	} 
    	//returning the list.
    	return result;
    }
