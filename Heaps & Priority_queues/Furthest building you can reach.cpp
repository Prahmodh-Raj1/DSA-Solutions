//prob link: https://leetcode.com/problems/furthest-building-you-can-reach/
//TC: O(N*log(ladders)) SC: O(ladderss)
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        int ind=1;
        if(n==1) return 0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=1;i<n;i++){
            if(heights[i]-heights[i-1]>0){
                pq.push(heights[i]-heights[i-1]);
                if(pq.size()>ladders){
                    //we need to use bricks for this move
                    bricks-=pq.top();
                    if(bricks<0) return i-1; 
                    pq.pop();
                }
            }
        }
        return n-1;
    }
};
/*
Heap heap store k height difference that we need to use ladders.
Each move, if the height difference d > 0,
we push d into the priority queue pq.
If the size of queue exceed ladders,
it means we have to use bricks for one move.
Then we pop out the smallest difference, and reduce bricks.
If bricks < 0, we can't make this move, then we return current index i.
If we can reach the last building, we return A.length - 1.*/
