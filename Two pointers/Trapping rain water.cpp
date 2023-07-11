//Problem link: https://leetcode.com/problems/trapping-rain-water
//TC: O(N) SC: O(1)
class Solution {
    public int trap(int[] height) {
        int left=0,right=height.length-1;
        int maxleft=0;
        int maxright=0;
        int ans=0;
        while(left<right){
            if(height[left]<=height[right]){
                //water is settling on the left hand side
                maxleft = Math.max(maxleft,height[left]);
                ans+=(maxleft-height[left]);
                left++;
            }else{  //water settles on the right
                maxright = Math.max(maxright,height[right]);
                ans+=(maxright-height[right]);  //calcaulating water that can settle
                right--;
            }
        }
        return ans;
    }
}

//tc: o(n) SC: O(N)
class Solution {
public:
    int trap(vector<int>& heights) {
        int n=heights.size();
        //water will settle only if a block has a larger block on either side of it
        vector<int> maxleft(n,-1),maxright(n,-1);
        maxleft[0]=heights[0];
        maxright[n-1]=heights[n-1];
        for(int i=1;i<n;i++){
            maxleft[i]=max(maxleft[i-1],heights[i]);
        }
        for(int i=n-2;i>=0;i--){
            maxright[i]=max(maxright[i+1],heights[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int waterlevel = min(maxleft[i],maxright[i]);
            if(waterlevel>heights[i]) ans+=(waterlevel-heights[i]);
        }
        return ans;
        
    }
};
