//Problem link: https://leetcode.com/problems/binary-tree-maximum-path-sum
//TC: O(N) SC: O(N)
class Solution {
    int ans=Integer.MIN_VALUE;
    private int path(TreeNode root){
        if(root==null) return 0;
        int lmaxval = Math.max(0,path(root.left));  //finding the max path sum value in the left path
        int rmaxval = Math.max(0,path(root.right)); //finding the max path sum value in the right path
        ans = Math.max(ans,lmaxval + rmaxval + root.val);  //calculating current sum
        return Math.max(lmaxval,rmaxval) + root.val; //returning the max sum from both the paths
    }
    public int maxPathSum(TreeNode root) {
        path(root);
        return ans;
    }
}
