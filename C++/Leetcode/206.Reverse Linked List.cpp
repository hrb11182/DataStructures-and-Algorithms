/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
*/

//T-COMPLEXITY - O(n).
//S-COMPLEXITY - O(1).

/*
Initially create a dummy node and assign it to null now we make a next node and make it point on the next element of head now we take that head and make it point to dummy node(i.e NULL) now move dummy to head and head to head next(or next) now move the next to the head next (means new head next) now again do the same and make head point on dummy and now again move dummy to head and head to head next and so on we will keep on doing this untill your head reaches the NULL moment it occurs return thr dummy node because it was pointing on the new head.
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* dummyNode = NULL;
        while(head != NULL) {
        	ListNode* next = head->next;
// Initialising the next.
        	head->next = dummyNode;
// Making the head to point on dummy.
        	dummyNode = head;
// Moving dummyNode one step ahead.
        	head = next;
// Moving head one step ahead.
        }
        return dummyNode;
//Returning dummy node.
    }
};