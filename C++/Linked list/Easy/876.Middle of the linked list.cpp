/*
Given a non-empty, singly linked list with head node head, return a middle node of linked list.

If there are two middle nodes, return the second middle node.

 

Example 1:

Input: [1,2,3,4,5]
Output: Node 3 from this list (Serialization: [3,4,5])
The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
Note that we returned a ListNode object ans, such that:
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.
Example 2:

Input: [1,2,3,4,5,6]
Output: Node 4 from this list (Serialization: [4,5,6])
Since the list has two middle nodes with values 3 and 4, we return the second one.
 

Note:

The number of nodes in the given list will be between 1 and 100.
*/

//BRUTEFORCE
//T-COMPEXITY - O(n) + O(n/2).
//S-COMPLEXITY - O(1)

/*
Take a pointer and a counter variable traverse through the list and count the number of nodes in the counter now take a new variable say mid and store the count divided by two to mid in case of even count divided by 2 and then add 1 to the answer and store it in mid now take a dummy node and keep on moving the dummy node untill it reaches the node equal to the mid then return that node.
*/

//OPTIMAL SOLUTION (USING TORTORISE METHOD)
//T-COMPLEXITY - O(n/2)
//S-COMPLEXITY - O(1)

/*
Take two pointers slow and fast slow will move one step ata time and fast will move two steps so when fast reaches the end or crosses the end slow will be at the mid of the list return the node at slow pointer.
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next != NULL){
        	slow = slow->next;
        	fast = fast->next->next;
        }
        return slow;
    }
};