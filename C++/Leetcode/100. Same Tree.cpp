/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

Example 1:


Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:


Input: p = [1,2], q = [1,null,2]
Output: false
Example 3:


Input: p = [1,2,1], q = [1,1,2]
Output: false
*/

/*
We will traverse both the trees by two types (inorder, preorder or post order) and then compare both the answers if they sre same then both tree are smae
*/

class Solution {
public:

	void inorder(TreeNode* root, vector<int>& v){
		if(root!=NULL){
			inorder(root->left, v);
			v.push_back(root->val);
			inorder(root->right, v);
		}else{
			v.push_back(10e5);
		}
	}
	void preorder(TreeNode* root, vector<int>& v){
		if(root!=NULL){
			v.push_back(root->val);
			preorder(root->left, v);
			preorder(root->right, v);
		}else{
			v.push_back(10e5);
		}
	}
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> inp, inq, prep, preq;
        inorder(p, inp);
        inorder(q, inq);

        preorder(p, prep);
        preorder(q, preq);

        if(inp == inq and prep == preq)
        	return true;
        else
        	false;
    }
};