/*
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

 

Example 1:


Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
Example 2:

Input: head = [0]
Output: 0
Example 3:

Input: head = [1]
Output: 1
Example 4:

Input: head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
Output: 18880
Example 5:

Input: head = [0,0]
Output: 0
 

Constraints:

The Linked List is not empty.
Number of nodes will not exceed 30.
Each node's value is either 0 or 1.
*/

class Solution {
public:
	int binaryTodecimal(string s){
		int dec=0;
// Declared a variable dec(decimal) of int type.
		int base=1;
// Taken a base variable which stores the 1 initaially and will be multiplied by 2 whwnever we encounter the 1 in string.
		int n = (int)s.length();
		for(int i=n; i>=0;i--){
// Traversing the string from back.
			if(s[i] == '1')
// Whenever we encounter the '1' then we add base to the decimal.
				dec+base;
			base*=2
// base will be multiplied by 2 and will be ready to be added to base when ever we encounter 1 again.
		}
		return dec;
// return dec.
	}
	int getDecimalValue(ListNode* head){
		string s;
// Decleration of a string.
		while(head!=NULL){
// Traversing through linkedlist untill head reaches to null.
			int data = head->val;
// Taken a variable data and inserted the value of head.
			char x = (data==1) ? '1' : '0';
// Taken a character x and converted the data from int to char and stored in the string s.
			s=s+x;
			head=head->next;
// Moved the head pointer to the next value of the linked list.			
		}
// This function is used to convert the given linked list to a string.
		int ans = binaryTodecimal(s);
// Function call.
		return ans;
	}
};