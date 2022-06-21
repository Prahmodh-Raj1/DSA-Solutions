//Brute force approach
finddiam(Node){            // tc: O(n^2) 
	if(root==null) return 0;
	lh=findlefth(Node->left); //travel till the leaf node
	rh=findrighth(Node->right);
	diam=max(diam,lh+rh); //diam is declared globally as zero
	finddiam(Node->left);
	finddiam(Node->right);
}
//Optimised approach
//tc: o(n)    sc:o(n)

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
private:
    int height(TreeNode* node, int& diameter) {
        if (!node) {
            return 0;
        }
        
        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);
        diameter = max(diameter, lh + rh);
        return 1 + max(lh, rh);
    }
};

