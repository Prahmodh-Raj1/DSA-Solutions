class solution{
public:
	vector<vector<int>> levelOrder(TreeNode* root){
		vector<vector<int>> ans;
		if(root==NULL) return ans;
		queue<TreeNode*> q;
		q.push(root);
		while(!q.empty()){       //TC: O(n)          SC:O(n) only the queue is taken into account
		//the vector ans is the thing we are returning so we dont consider that for calculating SC
			int size=q.size();
			vector<int> level;
			for(int i=0;i<size;i++){
				TreeNode *node=q.front();
				q.pop();
				if(node->left!=NULL) q.push(node->left);
				if(node->right!=NULL) q.push(node->right);
				level.push_back(node->val);
			}
			ans.push_back(level);
		}
		return ans;
	}
};
