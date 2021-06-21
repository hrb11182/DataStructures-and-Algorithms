/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
*/

//BRUTEFORCE
//T-COMPLEXITY - O(2n)
//s-COMPLEXITY - O(1)

/*
Take a dummy node and a variable counter whose value will be 1 innitially and traverse through the list untill you reach end and keep on increasing the value of counter at each step by one at the end of the list counter will become equal to the length of the list now take a variable toDelete and store the result of  subtraction of  the n (node from the end to delete) from the counter now use your dummy node and again start iterating through the list again and keep on increasing the counter untill counter become equal to the value of toDelete once it become equal delete that node and make previous node of deleted node to point on the next of the deleted node.


There is a edge case what if it asks to delete the first node means n (node from the end to delete) the input equals to the length of the list now in this case we will make head to point on its next node and we delete the head node if you dont delete it will also work fine without deleting.
*/

//OPTIMAL SOLUTION
//T-COMPLEXITY - O(n)
//S-COMPLEXITY - O(1)
/*
You need to create a dummy node and make it point to the head of the list and  take fast and slow pointer initialise them to that dummy node initially and then move fast pointer untill it reaches to nth element of list(node from the end to delete) the input value once it reaches there stop it now move the fast and slow pointers by  one step at a time untill fast reaches the last inde of list (means fast -> next == NULL) now make the element at the slow pointer to point on the slow next next and delete slow next element if required else you can leave it.


There is a edge case what if it asks to delete the first node means n (node from the end to delete) the input equals to the length of the list now in this case first pointer will reach at the end before both slow and fast move together so now slow will not move because fast will be already at the last position so now we will return dummy next as head.
*/


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *start = new ListNode();
        start -> next = head;
        ListNode *slow = start;
        ListNode *fast = start;

        for(int i = 1; i<=n; ++i)
        	fast = fast -> next;
        while(fast->next != NULL){
        	fast = fast->next;
        	slow = slow->next;
        }
        slow->next = slow->next->next;
        return start->next;
    }
};