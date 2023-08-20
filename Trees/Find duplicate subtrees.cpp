//Prob link: https://leetcode.com/problems/find-duplicate-subtrees
//TC: O(N) SC: O(H)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 /*To solve this problem, we can use a post-order traversal of the binary tree and serialize the subtrees. For each subtree, we can serialize its left and right children recursively and append its own value. By serializing the subtrees in this way, we can represent each subtree as a unique string. We can then use a hash table to keep track of the frequency of each serialized subtree. If the frequency of a serialized subtree is greater than 1, it means that the subtree is a duplicate. We can add the root node of the duplicate subtree to a vector and return it as the result*/
class Solution {
private:
    string serialize(TreeNode* cur,unordered_map<string,int>& subtree,vector<TreeNode*>& dupl){
        if(cur==NULL) return "#";
        string leftsubtree = serialize(cur->left,subtree,dupl);
        string rightsubtree = serialize(cur->right,subtree,dupl);
        string curs = leftsubtree+","+rightsubtree+","+to_string(cur->val);
        if(subtree.count(curs)) dupl.push_back(cur);
        subtree[curs]++;
        return curs;
    }
public:
    string serializeSubtrees(TreeNode* node, unordered_map<string, int>& subtrees, vector<TreeNode*>& duplicates) {
        if (!node) return "#"; // Null nodes are represented by '#'
        
        string left = serializeSubtrees(node->left, subtrees, duplicates);
        string right = serializeSubtrees(node->right, subtrees, duplicates);
        
        string s = left + "," + right + "," + to_string(node->val); // Serialize the current subtree
        
        if (subtrees[s] == 1) duplicates.push_back(node); // If a duplicate subtree is found, add to the vector
        
        subtrees[s]++;
        return s;
    }
 vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> subtrees; // Store serialized subtree and its frequency
        vector<TreeNode*> duplicates; // Store duplicate subtrees
        
        serializeSubtrees(root, subtrees, duplicates); // Traverse the tree and serialize subtrees
        
        return duplicates;
    }
};
