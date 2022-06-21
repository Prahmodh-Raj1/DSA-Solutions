//Postorder,preorder,inorder traversal all in one traversal
//using a stack, which stores node and num
//create vectors for preorder,inorder, postorder. we start with num=1
//if num is 1,node goes  into preorder, do num++ and push onto stack if left exists

//if num=2, node goes  into inorder, num++ and push onto stack if right exists
//if num=3, node goes  into postorder, 
//once num=3 and node is added onto postorder, we pop from the stack
//repeat the above process until stack is empty
//TC:O(3N) SC:O(4N)
class Solution {

public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*,int>> st; 
        st.push({root, 1}); 
        vector<int> pre, in, post;
        if(root == NULL) return post;

        while(!st.empty()) {
            auto it = st.top(); 
            st.pop(); 

            // this is part of pre
            // increment 1 to 2 
            // push the left side of the tree
            if(it.second == 1) {
                pre.push_back(it.first->val); 
                it.second++; 
                st.push(it); 

                if(it.first->left != NULL) {
                    st.push({it.first->left, 1}); 
                }
            }

            // this is a part of in 
            // increment 2 to 3 
            // push right 
            else if(it.second == 2) {
                in.push_back(it.first->val); 
                it.second++; 
                st.push(it); 

                if(it.first->right != NULL) {
                    st.push({it.first->right, 1}); 
                }
            }
            // don't push it back again 
            else { //it.second==3
                post.push_back(it.first->val); 
            }
        } 

        return post; 
    }
};

