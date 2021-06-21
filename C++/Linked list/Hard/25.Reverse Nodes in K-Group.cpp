/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
Example 3:

Input: head = [1,2,3,4,5], k = 1
Output: [1,2,3,4,5]
Example 4:

Input: head = [1], k = 1
Output: [1]
 

Constraints:

The number of nodes in the list is in the range sz.
1 <= sz <= 5000
0 <= Node.val <= 1000
1 <= k <= sz
*/



class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1) return head;
// If the linked list is empty or has just one element so we cant reverse it so we will return head.
        ListNode *dummy = new ListNode(0);
// Created a dummy node.
        dummy->next=head;
// Making the dummy node to point the head of the linked list.

        ListNode *cur = dummy, *nex = dummy, *pre = dummy;
// Decleration of the three dummy node.
        int count  = 0;
// decleration of count and initialising it to 0. 

        while(cur->next != NULL){
        	cur = cur->next;
        	count++;
        }
// This loop is to find the length of the linked list.
        while(count >= k){
// We keep on iterating untill the count remain equal or greater then k since we are reducing the value of count by k so if count become smaller then k means we left out some element which are less then k in numbers so cant be reversed.
        	cur = pre->next;
// This make the cur(current) to point on the first element of the part of the list of size k.
        	nex = cur->next;
// This will make the nex to point on the next element of the cur (ideally second element of the sublist of size k)
        	for(int i = 1; i<k; i++){
// Here we need to make k - 1 iterations to reverse the linked list of size k because always there is n-1 links in the list of size n. 
        		cur->next = nex->next;
// Since we make cur to point on the first element (see line 62) now this line  will make cur to point on the next element of nex.
        		nex->next = pre->next;
// This line made the next element of nex the first element
        		pre->next = nex;
// This line will make the last element of the first sub list as the pre for the next sublist.
        		nex = cur->next;
        	}
        	pre = cur;
        	count-=k;
// reducing coount by k because we reversed that number of elements of the list.
        }
        return dummy -> next;
// This will return the head of the modified linked list.
    }
};