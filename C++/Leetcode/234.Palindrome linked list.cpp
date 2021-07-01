/*
Given the head of a singly linked list, return true if it is a palindrome.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?
*/

//BRUTEFORCE
//T-COMPLEXITY - O(n) + O(n)
//S-COMPLEXITY - O(n)
/*
Taking all the elements and putting in some array and checking that the array is pallindromic or not if yes then list will also be pallindromic.
*/

//OPTIMAL APPROACH
//T-COMPLEXITY - O(n/2) + O(n/2) + O(n/2) + O(n/2) + O(n/2)
//S -COMPLEXITY - O(n)

/*
Find the middle of the linked list to do so take two pointers slow and fast move slow pointer by one step and fast by two the moment the fast pointer reaches the last or second last node we stop (in case the list has even number of elements so the left of the two middle element will be considered as the middle) since you find the middle point reverse the right half of the list and move the slow pointer by one step and take a dummuy node and make it point on the first element or head now start moving the dummy node and slow pointer simultaneously and compare the elements of both the pointers if matches move forward and the moment the slow pointer reaches the null stop now it shows that linked list is pallindromic now again find the mid point and reverse the right half to get the linked list in initial position.
*/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
        	return true;

        ListNode *slow = head;
        ListNode *fast = head;

        while(fast->next!=NULL && fast->next->next!=NULL){
        	slow = slow->next;
        	fast = fast->next->next;
        }

        slow->next = reverseList(slow->next);
        slow = slow->next;

        while(slow!=NULL){
        	if(head->val!=slow->val)
        		return false;
        	head = head->next;
        	slow = slow->next;
        }
        return true;
    }

    ListNode* reverseList(ListNode* head){
    	ListNode* pre=NULL;
    	ListNode* next=NULL;
    	while(head!=NULL){
    		next=head->next;
    		head->next=pre;
    		pre=head;
    		head=next;
    	}
    	return pre;
    }
};