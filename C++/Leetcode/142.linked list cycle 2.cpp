/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Notice that you should not modify the linked list.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:


Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:


Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
*/

//BRUTEFORCE
//T-COMPLEXITY-O(n)
//S_COMPLEXITY-O(n)

/*
Here we are using the hash table to detect the starting point of the loop we are going to traverse through the list and store all the nodes of the list not the elements of the list in the hash table and during traversel you will keep on checking that the node which you are going to store alraedy exist in the hash table or not if yes then that will be the starting point of the loop or you stop traversing untill you reach null.
*/

//Optimal solution using slow and fast pointer method.
//T-COMPLEXITY - O(n)
//S-COMPLEXITY - O(1)

/*
1st step(find the collission points) - In order to do that take two pointers (slow & fast) and make sure we move the slow pointer by one step and fast pointer by 2 steps simunteneously untill they collid.

2nd step(find the starting points of cycle) - Take a pointer( say it entry ) and make it point on the head of the linked list now you need to move entry as well as slow pointer( remember that slow poiner is in the collision state with the fast pointer during the execution of our first step) by 1 steps untill they dont collid and the point where they both collid is the starting point of the loop.
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL)
        	return NULL;

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *entry = head;

        while(fast -> next && fast -> next -> next){
        	slow = slow -> next;
        	fast = fast -> next -> next;
        	if(slow == fast){
        		while(slow != entry){
        			slow = slow -> next;
        			entry = entry -> next;
        		}
        		return entry;
        	}
        }
        return NULL;
    }
};