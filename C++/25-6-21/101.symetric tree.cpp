/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
*/

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if(!root)
			return true;
// If root node is null so it will be automatically symetric.
		return areMirror(root->left, root->right);
// Calling helper function by passing both the branches of root if present.
		}

		bool areMirror(TreeNode* t1, TreeNode* t2) {
// Taken node of branches of the root.
			if(!t1 || !t2)
				return (t1 == t2);
// IF both are null return both are equal also.

			if(t1->val != t2->val)
				return false;
// Else compare both of them.

			return ( areMirror(t1->left, t2->right) && areMirror(t1->right, t2->left));
// If they both got branches then again call the function on that branch nodes.
// Recursive function call.
		}
	};