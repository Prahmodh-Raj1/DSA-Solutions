//Problem link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst
//TC: O(N) SC: O(N)
lass Solution {
    Map<Integer,Integer> mp = new HashMap<>();
    
    private boolean helper(TreeNode root,int k){
        if(root==null) return false;
        if(mp.get(k-root.val)!=null){
            return true;
        }
        mp.put(root.val,1);
        return helper(root.left,k) || helper(root.right,k);
         
    }
    public boolean findTarget(TreeNode root, int k) {
        
        return helper(root,k);
        
    }
}
