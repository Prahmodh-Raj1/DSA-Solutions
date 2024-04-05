//Problem link: https://leetcode.com/problems/add-one-row-to-tree
//TC: O(E+N) SC: O(N)
class Solution {
    
    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if(depth==1){
            TreeNode newroot = new TreeNode(val);
            newroot.left = root;
            return newroot;
        }
        int level=0;
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.add(root);
        while(!q.isEmpty()){
            level++;
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode node = q.peek();
                q.poll();
                if(level==depth-1){
                    TreeNode n1 = new TreeNode(val);
                    TreeNode n2 = new TreeNode(val);
                    n1.left = node.left;
                    n2.right = node.right;
                    node.left =n1;
                    node.right=n2;
                }else{
                    if(node.left!=null) q.add(node.left);
                    if(node.right!=null) q.add(node.right);
                }
            }
            
        }
        return root;
    }
}
