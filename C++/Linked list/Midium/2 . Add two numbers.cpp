/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/


// This question has only the optimal approach.

/*
Here you will take two pointers (say l1 & l2) and make them point on the first element of both the linked lists and take two variable to store sum and carry (say sum & car) and we will take a dummy node (say dum) and a temprory node (say temp) which will point on dummy node now add l1, l2 & car and store them in sum(Adding value to the sum will take place one by one means first value of l1 will be added to sum ,then l2 & then car) and then add the result of sum to a new node and make the value of sum again zero and make the dummy node point on the newly created node  and move the temp pointer on that new node and also move l1 & l2 if car become zero and both l1 and l2 become null we will return the head of the linkedlist (dum.next).
*/

//T-COMPLEXITY - O(max(n1, n2))
//S-COMPLEXITY - O(n)

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry){
        	int sum = 0;
        	if(l1 != NULL){
        		sum += l1->val;
        		l1 = l1->next;
        	}
        	if(l2 != NULL){
        		sum += l2->val;
        		l2 = l2->next;
        	}
        	sum += carry;
        	carry = sum / 10;
        	ListNode *node = new ListNode(sum % 10);
        	temp -> next = node;
        	temp = temp -> next;
        }
        return dummy -> next;
    }
};