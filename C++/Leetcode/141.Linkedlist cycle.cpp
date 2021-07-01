/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
Example 2:


Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
Example 3:


Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
*/


//BRUTEFORCE
//T-COMPLEXITY - O(n)
//S-COMPLEXITY - O(n)


/*
Traverse through linked list and push the complete node to the hash table not only the value stored on the node because you may have multiple node witha the same value and during traversal before pushing the node to hashtable check that the node you are going to push already exist in the hashtable or not if yes return that node.

Method to store the node in hash table -> ????
*/

//OPTIMAL APPROACH - Using fast and slow pointers.
//T-COMPLEXITY - O(n)
//S-Complexity - O(1)

/*
Take two dummy nodes (fast and slow pointers) move slow pointer by one step and fast by 2 step it is certen that both the pointers going to meet at some point if there exists a cycle if there is no cycle then fast pointer will become null at the some point.
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL)
        	return false;

        ListNode *fast = head;
        ListNode *slow = head;

        while(fast -> next && fast -> next -> next){
// This while loop keep on running untill fast's next or next next element become null.
        	fast = fast -> next -> next;
        	slow = slow -> next;
        	if(fast == slow)
        		return true;
        }
        return false;
    }
};