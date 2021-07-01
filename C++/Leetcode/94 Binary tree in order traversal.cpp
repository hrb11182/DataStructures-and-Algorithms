/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,3,2]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
Example 4:


Input: root = [1,2]
Output: [2,1]
Example 5:


Input: root = [1,null,2]
Output: [1,2]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/


class Solution {
public:
	void inorder(TreeNode* root, vector<int>& ans){
		if(root!= NULL){
// Checking if root's value is not null.
			inorder(root->left, ans);
// Recursive call for every left node first all the calls for left node occur and then for right.
			ans.push_back(root->val);
// Storing the value of each node in answer the way they are traversed.
			inorder(root->right, ans);
// Recursive call for right nodes.
		}
	}

	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ans;
		inorder(root, ans);
// Helper function call.
		return ans;
	}
};