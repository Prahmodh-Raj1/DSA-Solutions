//Problem link: https://leetcode.com/problems/find-k-th-smallest-pair-distance/
//TC: O(Nlog(max-min)) SC: O(1)
class Solution {
public:
    bool check(vector<int>& nums,int k,int mid){
        int cnt=0,i=0,j=0;  //declaring a slow and fast pointer
        int n= nums.size();
        while(i<n or j<n){
            while(j<n and nums[j]-nums[i]<=mid){  //keep moving the fast pointer until the current mid is not exceeded
                j++;
            }
            cnt+=(j-i-1);  //counting the number of pairs
            i++;  //move the slow pointer to try obtaining more pairs that satisfy the condition
        }
        return cnt>=k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int low=0;
        int high=nums[nums.size()-1] - nums[0];
        while(low<high){
            int mid = (low+high)/2;
            if(check(nums,k,mid)) high=mid;
            else low= mid+1;
        }
        return low;
    }
};
/*determine whether there're at least k pairs whose distances are less than or equal to distance. We can sort the input array and use two pointers 
(fast pointer and slow pointer, pointed at a pair) to scan it. Both pointers go from leftmost end. If the current pair pointed at has a distance less
than or equal to distance, all pairs between these pointers are valid (since the array is already sorted), we move forward the fast pointer.
Otherwise, we move forward the slow pointer. By the time both pointers reach the rightmost end, we finish our scan and see if total counts exceed k*/
