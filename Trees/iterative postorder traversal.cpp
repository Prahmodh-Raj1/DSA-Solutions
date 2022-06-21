//Use two stacks, push the root onto st1, whenever we move to the next node, with both left and right
//nodes, push them onto st2. 


//Using one stack
class Solution{          //TC: O(2N)  SC:O(N) stack space
public:
	vector<int> iterpostorderTraversal(TreeNode* root){
		vector<int> postorder;
		if(root==NULL) return postorder;
		stack<TreeNode*> st1;
		TreeNode* current=root;
		while(current!=NULL or !st.empty()){         
			if(current!=NULL){      //cur keeps going left until cur is null
				st1.push(current);
				current=current->left;
			}else{
				TreeNode* temp=st1.top()->right;
				if(temp==NULL){
					temp=st1.top();
					st1.pop();
					postorder.push_back(temp->val);
					while(!st1.empty() && temp=st1.top()->right){
						temp=st1.top();
						st1.pop();
						postoder.push_back(temp->val);
					}
				}else current=temp;
			}
		}
		return postoder; 
	}
};
