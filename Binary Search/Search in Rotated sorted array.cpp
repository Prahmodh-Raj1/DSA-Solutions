//Problem link: https://leetcode.com/problems/search-in-rotated-sorted-array/
//TC:O(LogN) SC:O(1)class Solution {
public:
    int binarysearch(vector<int>& nums,int target,int beg,int end){
        while(beg<=end){
    	  int mid=(beg+end)/2;
    	  if(nums[mid]==target){
    		return mid;
		  }else if(nums[mid]>target){
			end=mid-1;
		  }else if(nums[mid]<target){
			beg=mid+1;
		  }
	    }
	    return -1;
    }
    int search(vector<int>& nums, int target) {
         int pivot=fpivot(nums);
        //if u didnt find pivot, it means array is not rotated
        if(pivot==-1){
            //do normal bsearch
            return binarysearch(nums,target,0,nums.size()-1);
        }
        //if pivot is found, we've found two ascending sorted arrays
        if(nums[pivot]==target){
            return pivot;
        }else if(nums[0]<=target){
            //search space is reduced to (start,pivot-1) coz all the numbers would be smaller than start
            return binarysearch(nums,target,0,pivot-1);
        }
            //we know that all elements from start to pivot are going to be greater than target, search space: (pivot+1,end)
            
        
        return binarysearch(nums,target,pivot+1,nums.size()-1);
    }
    int fpivot(vector<int>& nums){
        
    
        int start=0;
        int end=nums.size()-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(mid<end && nums[mid]>nums[mid+1]){ //preventing index out of bounds
                return mid;
            }else if(mid>start && nums[mid]<nums[mid-1]){ //preventing index out of bounds
                return mid-1;
            }else if(nums[mid]<=nums[start]){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return -1;
        
    }
};
