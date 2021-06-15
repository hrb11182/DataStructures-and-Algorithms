/*
Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.

 

Example 1:


Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: l1 = [], l2 = []
Output: []
Example 3:

Input: l1 = [], l2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both l1 and l2 are sorted in non-decreasing order.
*/

//BRUTEFORCE
//S-OPTIMAL - O(n1 + n2).
//T-OPTIMAL - O(n1 + n2).

//Join both the lists and store them in a new sorted list.

//T-OPTIMAL - O(n1 + n2).
//S-OPTIMAL - O(1).
//Here instead of using a new space we will be doing this in the given space by just changing the pointers of each node and make them point in a sorted order.
// first take two variable say l1 and l2.
//Compare the first node of both the lists and make l1 point on the smallest one.
//l2 to next one.
//make apointer result that will point on the smallest among both.
//Create a node temp and assign it to null this will remember the last node.
//Move your l1 untill it is smaller then l2 but before moving l1 dont forget to assign temp to l1.
//Keep repeating this untill l1 is smaller then the l2.
//Moment l2 become smaller then l1 break the link of temp from l1 and point it to l2.
//Once the above condition meet after doing the specified steps swap l1 and l2 and repet the process.
//After every swap assign temp to be null.

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	if (l1 == NULL) return l2;
    	if (l2 == NULL) return l1;
    	if (l1->val > l2->val) std::swap(l1, l2);
    	ListNode * res = l1;
    	while(l1 != NULL && l2 != NULL){
    		ListNode * temp = NULL;
    		while(l1 != NULL && l1->val <= l2->val){
    			temp = l1;
    			l1 = l1->next;
    		}
    		temp->next = l2;
//Above loop will work untill l1->val is smaller then or equal to l2 if l2 become smaller we will make temp point towards the l2.
    		std::swap(l1, l2);
    	}
    	return res;
    }
};