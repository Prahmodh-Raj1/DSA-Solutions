//Problem link: 
//TC:O(M*log(m*n)) SC: O(1)
/*
Let's consider search space. Obviously the lower bound should be 1, and the upper bound should be the largest value in the Multiplication Table, which is m * n,
then we have search space [1, m * n]. The overwhelming advantage of binary search solution to heap solution is that it doesn't need to explicitly calculate all
numbers in that table, all it needs is just picking up one value out of the search space and apply enough function to this value, to determine should we keep the
left half or the right half of the search space. In this way, binary search solution only requires constant space complexity, much better than heap solution.

Next let's consider how to implement enough function. It can be observed that every row in the Multiplication Table is just multiples of its index.
For example, all numbers in 3rd row [3,6,9,12,15...] are multiples of 3. Therefore, we can just go row by row to count the total number of entries less 
than or equal to input num
*/
class Solution {
public:
    bool feasible(int mid,int m,int n,int k){
        int val=0;
        for(int i=1;i<=m;i++){
            int add=min(n,mid/i);
            if(add==0) break;
            val+=add;
        }
        return val>=k;
    }
    int findKthNumber(int m, int n, int k) {
        int low=1;
        int high=m*n;
        while(low<high){
            int mid = (low+high)/2;
            if(feasible(mid,m,n,k)){
                high=mid;
            }else low=mid+1;
        }
        return low;
    }
};
