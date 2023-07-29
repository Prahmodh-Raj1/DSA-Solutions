//Problem link: https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
//TC: O(N) SC: O(N)
class Solution {
private:
bool isLeaf(Node * root) {
  return !root -> left && !root -> right;
}

void addLeftBoundary(Node * root, vector < int > & res) {
  Node * cur = root -> left;
  while (cur) {
    if (!isLeaf(cur)) res.push_back(cur -> data);
    if (cur -> left) cur = cur -> left;
    else cur = cur -> right;
  }
}
void addRightBoundary(Node * root, vector < int > & res) {
  Node * cur = root -> right;
  vector < int > tmp;
  while (cur) {
    if (!isLeaf(cur)) tmp.push_back(cur -> data);
    if (cur -> right) cur = cur -> right;
    else cur = cur -> left;
  }
  //store the right nodes in an temmp array, then reverse the elements and add to main array
  for (int i = tmp.size() - 1; i >= 0; --i) {
    res.push_back(tmp[i]);
  }
}

void addLeaves(Node * root, vector < int > & res) {
    //doing a preorder traversal to ensure that only the leaf nodes are taken
  if (isLeaf(root)) {
    res.push_back(root -> data);
    return;
  }
  if (root -> left) addLeaves(root -> left, res);
  if (root -> right) addLeaves(root -> right, res);
}
public:
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector < int > res;
        if (!root) return res;

        if (!isLeaf(root)) res.push_back(root -> data);

        addLeftBoundary(root, res);

  // add leaf nodes
        addLeaves(root, res);

        addRightBoundary(root, res);
        return res;
    }
};
